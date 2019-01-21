#ifndef __HOOK_H__
#define __HOOK_H__

#include <sys/types.h>
#include <openssl/aes.h>

typedef struct Hooker {
	ssize_t (*read)(int fd, void* buf, size_t nbytes);
	ssize_t (*write)(int fd, const void* buf, size_t n);
	int (*AES_set_encrypt_key)(const unsigned char* userKey, const int bits, AES_KEY* key);
	int (*AES_set_decrypt_key)(const unsigned char* userKey, const int bits, AES_KEY* key);
	void (*AES_cbc_encrypt)(const unsigned char* in, unsigned char* out, size_t length,
			const AES_KEY* key, unsigned char* ivec, const int enc);
} Hooker;

#endif /* __HOOK_H__ */

