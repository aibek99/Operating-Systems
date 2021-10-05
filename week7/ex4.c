#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* reallocate(void* ptr, int n2) {
    if (ptr == NULL) {
        return malloc(n2 * sizeof(void*));
    }
    if (n2 == 0) {
        free(ptr);
        ptr = NULL;
        return ptr;
    }
    void* newptr = ptr;
    ptr = malloc(n2 * sizeof(void*));
    memcpy(ptr, newptr, n2);
    free(newptr);
    return ptr;
}

int main(void) {
    printf("Enter original array size : ");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = malloc(n1 * sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;

		printf("%d ", a1[i]);
	}

	printf("\nEnter new array size : ");
	int n2=0;
	scanf("%d",&n2);

	a1 = reallocate(a1, n2);
	for (int i = n1; i < n2; i ++) {
        a1[i] = 0;
	}


	for(i=0; i<n2;i++){
		printf("%d ", a1[i]);
	}
	printf("\n");

    return EXIT_SUCCESS;
}


