#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	char a[100];
	fgets(a, 100, stdin);
	int n = strlen(a);
	for (int i = 0; i < n / 2; i ++) {
		char tmp = a[n - 1 - i];
		a[n - 1 - i] = a[i];
		a[i] = tmp;
	}
	fputs(a, stdout);
	printf("\n");
	return EXIT_SUCCESS;
}
