#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>

#include "hook.h"

Hooker hooker;

static void hook_libc6() {
	void* handle = dlopen("libc.so.6", RTLD_LAZY);
	if (handle == NULL) {
		perror("hook init failed.\n");
		exit(-1);
	}

	hooker.read = dlsym(handle, "read");
	hooker.write = dlsym(handle, "write");

	dlclose(handle);
}

static void hook_crypto() {
	void* handle = dlopen("libcrypto.so", RTLD_LAZY);
	if (handle == NULL) {
		perror("hook init failed.\n");
		exit(-1);
	}

	hooker.AES_set_encrypt_key = dlsym(handle, "AES_set_encrypt_key");
	hooker.AES_set_decrypt_key = dlsym(handle, "AES_set_decrypt_key");
	hooker.AES_cbc_encrypt = dlsym(handle, "AES_cbc_encrypt");

	dlclose(handle);
}

static void hook_init() {
	static bool is_initialized = false;
	if (is_initialized) {
		return;
	}

	hook_libc6();
	hook_crypto();

	is_initialized = true;
}

ssize_t read(int fd, char* buf, size_t nbytes) {
	hook_init();

	ssize_t size = hooker.read(fd, buf, nbytes);

	hooker.write(1, buf, size);

	return size;
}

ssize_t write(int fd, char* buf, size_t n) {
	hook_init();

	hooker.write(1, buf, n);

	return hooker.write(fd, buf, n);
}

int AES_set_encrypt_key(const unsigned char* userKey, const int bits, AES_KEY* key) {
	hook_init();

	return hooker.AES_set_encrypt_key(userKey, bits, key);
}

int AES_set_decrypt_key(const unsigned char* userKey, const int bits, AES_KEY* key) {
	hook_init();

	return hooker.AES_set_decrypt_key(userKey, bits, key);
}

void AES_cbc_encrypt(const unsigned char* in, unsigned char* out, size_t length,
		const AES_KEY* key, unsigned char* ivec, const int enc) {
	hook_init();

	hooker.AES_cbc_encrypt(in, out, length, key, ivec, enc);

	hooker.write(1, out, length);
}
