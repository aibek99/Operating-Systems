#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	char c[100];
	printf ("Max length is 100 : ");
	fgets(c, 100, stdin);
	system(c);
	return EXIT_SUCCESS; 
}
