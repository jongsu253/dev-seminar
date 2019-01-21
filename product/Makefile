
PROG_NAME := sample.out

SOURCE := main.c \
		  memory_transfer.c \
		  file_transfer.c	\
		  cipher.c

CC = gcc
CFLAGS = -m32
LDFLAGS = -lcrypto

all: product generator

product: $(SOURCE)
	$(CC) -o $(PROG_NAME) $^ $(CFLAGS) $(LDFLAGS)

generator: generator.c cipher.c
	$(CC) -o gen $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf $(PROG_NAME) gen
