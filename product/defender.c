#include "defender.h"

#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>

static Defender defender;

void init_libc6() {
	void* handle = dlopen("libc.so.6", RTLD_LAZY);
	if (handle == NULL) {
		exit(-1);
	}

	defender.read = dlsym(handle, "read");
	defender.write = dlsym(handle, "write");

	dlclose(handle);
}

void init_crypto() {
	void* handle = dlopen("libcrypto.so", RTLD_LAZY);
	if (handle == NULL) {
		exit(-1);
	}

	defender.AES_set_encrypt_key = dlsym(handle, "AES_set_encrypt_key");
	defender.AES_set_decrypt_key = dlsym(handle, "AES_set_decrypt_key");
	defender.AES_cbc_encrypt = dlsym(handle, "AES_cbc_encrypt");

	dlclose(handle);
}

Defender* get_defender() {
	static bool is_initialized = false;
	if (is_initialized) {
		return &defender;
	}

	init_libc6();
	init_crypto();

	is_initialized = true;

	return &defender;
}
