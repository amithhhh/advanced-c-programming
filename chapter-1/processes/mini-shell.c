#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 4096

int main(void) {
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;

		if ((pid = fork()) < 0)
			perror("Fork Error");

		else if (pid == 0) {
			execlp(buf, buf, (char *)0);
			perror("Execute Error");
			exit(127);
		}

		if ((pid = waitpid(pid, &status, 0)) < 0)
			perror("Wait Error");

		printf("%% ");
	}
	return 0;
}
