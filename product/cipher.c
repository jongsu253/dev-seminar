#include <openssl/aes.h>

const static unsigned char key[] = {
    0x00, 0x11, 0x22, 0x33,
    0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xAA, 0xBB,
    0xCC, 0xDD, 0xEE, 0xFF
};

void encrypt(char* plain_text, char* output_text, int length) {
	unsigned char iv[AES_BLOCK_SIZE] = {};
	int i;

	AES_KEY aes_key;

	AES_set_encrypt_key(key, sizeof(key) * 8, &aes_key);

    for(i = 0 ; i < length ; i += AES_BLOCK_SIZE) {
        AES_cbc_encrypt(plain_text + i, output_text + i, AES_BLOCK_SIZE, &aes_key, iv, AES_ENCRYPT);
    }
}

void decrypt(char* encrypted_text, char* output_text, int length) {
	unsigned char iv[AES_BLOCK_SIZE] = {};
	int i;

	AES_KEY aes_key;

	AES_set_decrypt_key(key, sizeof(key) * 8, &aes_key);

	for(i = 0 ; i < length ; i += AES_BLOCK_SIZE) {
        AES_cbc_encrypt(encrypted_text + i, output_text + i, AES_BLOCK_SIZE, &aes_key, iv, AES_DECRYPT);
    }
}
