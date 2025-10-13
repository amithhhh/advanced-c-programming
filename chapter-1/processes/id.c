#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	printf("hello world from process id %ld\n", (long)getpid());
	return 0;
}
