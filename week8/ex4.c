#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(void) {
    for (int i = 1; i <= 10; i ++) {
        int sz = 10 * 1024 * 1024;
        char *ar = malloc(sz);
        memset(ar, 0, sz);
        struct rusage memory;
        getrusage(RUSAGE_SELF, &memory);
        printf("Memuse: %ld\n", memory.ru_maxrss);
        sleep(1);
    }
    return EXIT_SUCCESS;
}




