#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ageing(int *num, int r_bit) {
    *num = (*num >> 1) | (r_bit << 7);
}

int main(void) {
    int n, m, hitcount = 0, miscount = 0, cnt = 0, mx = 0;
    scanf("%d%d", &n, &m);
    int *t = calloc((m + 1), sizeof(int));
    int *a = calloc((m + 1), sizeof(int));

    double r = 0;
    for (int i = 1; i <= m; i ++) {
        scanf("%d%d", &t[i], &a[i]);    /// t[i] - time, a[i] - page number
        if (a[i] > mx) {
            mx = a[i];
        }
    }

    int *age = calloc((mx + 1), sizeof(int));

    int *ar = calloc((mx + 1), sizeof(int));  /// keeps age of i'th page
    int *frame = calloc((n + 1), sizeof(int));
    bool *r_bit = calloc((n + 1), sizeof(bool));
    int clock = 0;

    for (int i = 1; i <= m; i ++) {   /// does i'th query

        if (clock != t[i]) {
            memset(r_bit, false, sizeof((n + 1) * sizeof(bool)));
            for (int j = 1; j <= n; j ++) {
                int in_j = frame[j];
                ar[in_j] >>= 1;
            }
        }

        bool hit = false;
        int address = 0;
        for (int j = 1; j <= n; j ++) {   /// checks if i'th query is hit or miss
//            printf ("%d ", frame[j]);
            if (frame[j] == a[i]) {
                hit = true;
                address = j;   /// if it is hit then address - is index of hitted page
            }
        }
//        printf ("\n");

        hitcount += hit;

        if (!hit) {
            if (cnt < n) {
                for (int j = 1; j <= n; j ++) {  /// if free place is available in frame
                    if (frame[j] == 0) {
                        address = j;
                        break;
                    }
                }
                cnt ++;   /// cnt - keeps number of pages in frame
            } else {      /// if no free places available in frame
                int mn_cnt = 1 << 10, pagenum = mx + 1;
                for (int j = 1; j <= n; j ++) {
                    int in_j = frame[j];
                    if (mn_cnt > ar[in_j]) {
                        mn_cnt = ar[in_j];
                        pagenum = frame[j];
                        address = j;
                    }
                    if (mn_cnt == ar[in_j] && pagenum > frame[j]) {
                        pagenum = frame[j];
                        address = j;
                    }
                }
            }
        }

        printf ("%d\n", hit);
//        printf ("Address & deleting object : %d %d\n", address, frame[address]);

        int inframe = frame[address];

        frame[address] = a[i];
        r_bit[address] = 1;
        if (!hit) ar[inframe] = 0;

        for (int j = 1; j <= n; j ++) {
            int in_j = frame[j];
            ar[in_j] |= r_bit[j] << 7;
        }

        clock = t[i];
    }

    miscount = m - hitcount;

    printf ("%.7lf\n", (hitcount + 0.0) / (miscount + 0.0));

    return EXIT_SUCCESS;
}

/*

2 4
1 3
2 1
2 2
2 3



*/

