#include "transfer.h"

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

#include "cipher.h"

char name[30];
char phone[30];
char address[30];

static void parse() {
	static bool is_parsed = false;

	if (is_parsed) {
		return ;
	}

	int fd = open("credential", O_RDONLY);

	char cipher_text[100] = {};
	char plain_text[100];

	int size = read(fd, cipher_text, 100);
	decrypt(cipher_text, plain_text, size);

	sscanf(plain_text, "%s %s %s", name, phone, address);

	is_parsed = true;

	close(fd);
}

static char* get_name() {
	return name;
}

static char* get_phone() {
	return phone;
}

static char* get_address() {
	return address;
}

const static Transfer transfer = {
	.get_user_name = get_name,
	.get_user_phone = get_phone,
	.get_user_address = get_address
};

Transfer* get_file_transfer() {
	parse();

	return &transfer;
}

