#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int sig) {
	printf("Are you mad? You tried to divide by zero!\n");
	exit(1);
}

int main(void) {
	int a, b, c;
	signal(SIGFPE, handle_sigfpe);
	a = 10;
	b = 0;

	c = a / b;
	return 0;
}
