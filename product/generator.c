#include <fcntl.h>
#include <string.h>
#include <openssl/aes.h>

#include "cipher.h"

#define BUFFER_SIZE 50

int main(int argc, char* argv[]) {
	char plain_text[BUFFER_SIZE] = "Buzzvil 010-XXXX-XXXX Daerim";
	char cipher_text[BUFFER_SIZE];

	int size = (strlen(plain_text) + AES_BLOCK_SIZE) / AES_BLOCK_SIZE * AES_BLOCK_SIZE;

	encrypt(plain_text, cipher_text, size);

	int fd = open ("credential", O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	write(fd, cipher_text, size);
}
