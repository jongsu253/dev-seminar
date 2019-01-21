#ifndef __HOOK_H__
#define __HOOK_H__

#include <sys/types.h>

typedef struct Hooker {
    ssize_t (*read)(int fd, void* buf, size_t nbytes);
    ssize_t (*write)(int fd, const void* buf, size_t n);
} Hooker;

#endif /* __HOOK_H__ */
