#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) { 
	int a, b;
	scanf("%d%d", &a, &b);
	Swap(&a, &b);
	printf ("%d %d\n", a, b);
	return EXIT_SUCCESS;
}
