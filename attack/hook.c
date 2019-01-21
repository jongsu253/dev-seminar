#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>

#include "hook.h"

Hooker hooker;

static void hook_init() {
    static is_initialized = false;
    if (is_initialized) {
        return;
    }

    void* handle = dlopen("libc.so.6", RTLD_LAZY);
    if (handle == NULL) {
        perror("hook init failed.\n");
		exit(-1);
    }

    hooker.read = dlsym(handle, "read");
    hooker.write = dlsym(handle, "write");

    dlclose(handle);

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
