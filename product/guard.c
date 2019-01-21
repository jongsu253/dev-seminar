#include "guard.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>

void init_guard() {
	if (ptrace(PTRACE_TRACEME) == -1) {
		perror("Don't traceme!\n");
		exit(-1);
	}
}
