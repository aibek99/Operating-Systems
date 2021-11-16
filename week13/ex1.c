#include <stdio.h>
#include <stdlib.h>

int n = 0, m = 0; /// n - amount of processes, m - number of resource types

int rowch(int R[n + 5][m + 5], int r, int A[m + 5]) {
    for (int i = 1; i <= m; i ++) {
        if (R[r][i] > A[i]) return 0;
    }
    return 1;
}

int main(void){
    FILE *rf = fopen("input.txt", "r");
    FILE *wf = fopen("output.txt","w");
    if (rf == NULL) {
        printf ("Input file is not found!");
        exit(1);
    }
    char ch, flag = 'f';
    int cnt = 0, cn = 0, num = 0, last;
    while ((ch = fgetc(rf)) != EOF) {
        if ('0' <= ch && ch <= '9') flag = 't';
        if (ch == ' ') {
            if (flag == 't') cnt ++;
            flag = 'f';
        }
        if (ch == '\n') {
            if (flag == 't') cnt ++;
            if (m == 0) m = cnt;
            if (cnt == 0 && last != 0) cn ++;
            if (cn == 2 && cnt != 0) n ++;
            last = cnt;
            flag = 'f';
//            printf ("%d\n", cnt);
            cnt = 0;
        }
    }
    printf ("%d %d\n", n, m);
    fseek(rf, 0, SEEK_SET);

    int E[m + 5];
    int A[m + 5];
    int C[n + 5][m + 5], R[n + 5][m + 5];
    int check[n + 5];
    memset(check, 0, sizeof(check));

    for (int i = 1; i <= m; i ++) {
        fscanf (rf, "%d", &E[i]);
    }
    for (int i = 1; i <= m; i ++) {
        fscanf (rf, "%d", &A[i]);
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            fscanf (rf, "%d", &C[i][j]);
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            fscanf (rf, "%d", &R[i][j]);
        }
    }



    while (1) {
        int f = 0;
        for (int i = 1; i <= n; i ++) {
            if (check[i] == 0) {
                check[i] = rowch(R, i, A);
                if (check[i] == 1) {
                    f = 1;
                    for (int j = 1; j <= m; j ++) {
                        A[j] += C[i][j];
                    }
                }
            }
        }
        if (f == 0) break;
    }

    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        if (check[i] != 0) sum ++;
    }

    if (sum == n) {
        fprintf (wf, "All processes are terminated.\n");
        return EXIT_SUCCESS;
    }

    fprintf (wf, "Deadlocked processes : ");
    for (int i = 1; i <= n; i ++) {
        if (check[i] == 0) {
            fprintf (wf, "%d ", i);
        }
    }

    fclose(rf);
    return EXIT_SUCCESS;
}

