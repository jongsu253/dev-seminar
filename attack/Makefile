
PROG_NAME := hook.so

SOURCE := hook.c

CC := gcc
CFLAGS := -m32 -shared -fPIC -fpic
LDFLAGS := -ldl

all: hook

hook: $(SOURCE)
	$(CC) -o $(PROG_NAME) $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf $(PROG_NAME)
