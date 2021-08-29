#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf ("%d\n\n %f\n\n %f\n\n", a, b, c);
	return EXIT_SUCCESS;
}
