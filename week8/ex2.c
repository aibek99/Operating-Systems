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

/**

In the beginning when I run vmstat 1, after launching ex2 in the background, I found
that free memory is decreasing. But others parts of memory swpd, buff, cache changed
a little bit in 1 or 2 rows.

procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 4  0  16972 204572 108568 2060908    0    1   137   327  490  945 15  2 83  0  0
 0  0  16972 194240 108568 2060908    0    0     0     8  273  374  3  0 96  0  0
 0  0  16972 184004 108568 2060948    0    0     0     0  318  488  7  0 93  0  0
 4  0  16972 173924 108568 2060948    0    0     0     0  298  419  6  0 93  0  0
 0  0  16972 163592 108568 2060948    0    0     0     0  309  493  3  0 97  0  0
 0  0  16972 153260 108568 2060948    0    0     0     0  343  486  7  0 93  0  0
 4  0  16972 143180 108568 2060948    0    0     0     0  284  427  4  0 96  0  0
 0  0  16972 132848 108576 2060940    0    0     0    12  276  373  4  0 95  2  0
 0  0  16972 234412 108576 2060948    0    0     0     0  380  557  7  1 93  0  0
 1  0  16972 234412 108576 2060948    0    0     0     0  245  340  3  0 97  0  0
 0  0  16972 234412 108576 2060948    0    0     0     0  263  412  4  0 96  0  0
 0  0  16972 244616 108576 2060948    0    0     0     0  620 1152  9  1 90  0  0
 0  0  16972 244868 108576 2060948    0    0     0     4  278  340  5  0 95  0  0


**/


/**

VIRT memories usage is increased
In MiB Mem: free memory is decreased and usage is increased

**/
