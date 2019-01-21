#include "guard.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>

void init_guard() {
	int pid;

	pid = fork();
	if (pid == 0) {
		int ppid = getppid();

		if (ptrace(PTRACE_ATTACH, ppid, 0, 0) < 0) {
			exit(-1);
		}
		ptrace(PTRACE_CONT);

		sleep(5);
	} else {
		int status;
		waitpid(pid, &status, 0);
	}

}
