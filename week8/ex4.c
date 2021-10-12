#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    for (int i = 1; i <= 10; i ++) {
        int sz = 10 * 1024 * 1024;
        char *ar = malloc(sz);
        memset(ar, 0, sz);
        sleep(1);
    }
    return EXIT_SUCCESS;
}




