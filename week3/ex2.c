#include <stdio.h>

void bubble_sort(int n, int a[]) {
	for (int i = n - 1; i >= 0; i --) {
		for (int j = 0; j < i; j ++) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	printf ("%d\n", n);
	for (int i = 0; i < n; i ++) {
		printf ("%d ", a[i]);
	}
	printf ("\n");
}

int main(void) {
	int a[] = {9, 1, 23, 5, 6 ,8};
	int n = sizeof(a) / sizeof(*a);
	bubble_sort(n, a);
	for (int i = 0; i < n; i ++) {
		printf ("%d ", a[i]);
	}
	printf ("\n");
	return 0;
}


