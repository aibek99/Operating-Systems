#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	sscanf(argv[1], "%d", &n);
	char stars[n + n];
	stars[n + n - 1] = '\0';
	for (int i = 0; i < n + n - 1; i ++) {
		stars[i] = ' ';
	}
	stars[n - 1] = '*';
	for (int i = n - 1; i >= 0; i --) {
		fputs(stars, stdout);
		printf ("\n");
		if (i > 0) stars[i - 1] = stars[n - 1 + (n - i)] = '*';
	}
	return EXIT_SUCCESS;
}
