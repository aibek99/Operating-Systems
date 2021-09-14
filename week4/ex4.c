#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
	char c[1000];
	char *str[100], *path="/home/comp/Operating-Systems/week4";
	int i = 0;
	fgets(c, 1000, stdin);
	char *nstr = strtok(c, " ");
	str[i ++] = path;
	while (nstr != NULL) {
		str[i ++] = nstr;
		nstr = strtok(NULL, " ");
	}
	str[i] = NULL;
	if (fork() == 0) {
		execve(path, str, NULL);
	}
	return EXIT_SUCCESS;
}

