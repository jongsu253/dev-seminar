
PROG_NAME := sample.out

SOURCE := main.c \
		  memory_transfer.c \
		  file_transfer.c

CC = gcc
CFLAGS = -m32
LDFLAGS =

all: product

product: $(SOURCE)
	$(CC) -o $(PROG_NAME) $^ $(CFLAGS) 

clean:
	rm -rf $(PROG_NAME)
