#include <stdio.h>

int main(void) {
	int c;
	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF)
			perror("Error");

	if(ferror(stdin))
		perror("Input Error");
	return 0;
}
