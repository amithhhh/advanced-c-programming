#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dirp;

	if (argc != 2)
		perror("usage: ls directory_name");

	if ((dp = opendir(argv[1])) == NULL)
		perror("can't open the directory");

	while ((dirp = readdir(dp)) != NULL) {
		printf("%d ", dirp->d_ino);
		printf("%s", dirp->d_name);

		switch (dirp->d_type) {
			case DT_REG:	printf("(regular file)\n");
					break;
			case DT_DIR:	printf("(directory)\n");
					break;
			case DT_LNK:	printf("(symlink\n)");
					break;
			default:	printf("(others)\n");
					break;
		}
	}
	closedir(dp);
	return 0;
}
