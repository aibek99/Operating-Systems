#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

struct process {
    int tim[6];
/**
    tim[0]  /// Process id - length 10
    tim[1]  /// Arrival time - length 12
    tim[2]  /// Burst time - length 10
    tim[3]  /// Waiting time - length 12
    tim[4]  /// Completion time - length 15
    tim[5]  /// Turnaround time - length 15
**/
};

typedef struct process process;

process *arr, *proces;

/// Accepts reference of two integers
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/// swaps two processes data
void pro_swap(int a, int b) {
    for (int i = 0; i < 6; i ++) {
        swap(&arr[a].tim[i], &arr[b].tim[i]);
    }
}


/// Comparator compares two process, depending on the priority given by array 'order'
int comp(process a, process b, int* order) {
    for (int i = 0; i < 6; i ++) {
        if (a.tim[order[i]] < b.tim[order[i]]) return 1;
        else if (a.tim[order[i]] == b.tim[order[i]]) continue;
        else break;
    }
    return 0;
}

/// Heap sort is used to sort given processes, and implement priority queue
void sift_up(int ind, int* order) {
    while (1) {
        if (comp(arr[ind], arr[ind / 2], order)) {
            pro_swap(ind, ind / 2);
            ind /= 2;
        } else break;
    }
}

void sift_down(int n, int* order) {
    int ind = 1;
    while (1) {
        int pos = ind;
        if (ind * 2 <= n && comp(arr[ind * 2], arr[pos], order)) pos = ind * 2;
        if (ind * 2 + 1 <= n && comp(arr[ind * 2 + 1], arr[pos], order)) pos = ind * 2 + 1;
        if (ind == pos) break;
        pro_swap(ind, pos);
        ind = pos;
    }
}

/// prints all processes with their arrival, burst, waiting, turnaround, completion times and id
void print(process *ar, int n) {
    printf ("Process id  Arrival time  Burst time  Waiting time  Completion time  Turnaround time\n");
    for (int i = 1; i <= n; i ++) {
		printf ("%10d %13d %11d %13d %16d %16d\n", ar[i].tim[0], ar[i].tim[1], ar[i].tim[2], ar[i].tim[3], ar[i].tim[4], ar[i].tim[5]);
	}
	printf ("\n");
}

/// add a process to priority queue
void add_to_queue(process a, int *pos, int* order) {
    *pos = *pos + 1;
    arr[*pos] = a;
    sift_up(*pos, order);
}

/// deletes the first element of a priority queue
process delete_from_queue(int *sz, int* order) {
    process res = arr[1];
    arr[1] = arr[*sz];
    *sz = *sz - 1;
    if (*sz > 0) sift_down(*sz, order);
    return res;
}

/// Calculate the Waiting time
void calculate_WT(process *arr, int n) {
    for (int i = 2; i <= n; i ++) {
        arr[i].tim[3] = arr[i].tim[4] - arr[i].tim[1] - arr[i].tim[2];
        if (arr[i].tim[3] < 0) arr[i].tim[3] = 0;
    }
}

/// Calculate completioin time
void calculate_CT(process *arr, int n) {
    arr[0].tim[4] = arr[0].tim[1] + arr[0].tim[2];
    for (int i = 1; i <= n; i ++) {
        arr[i].tim[4] = arr[i - 1].tim[4] + arr[i].tim[2];
    }
}

/// Calculate turnaround time
void calculate_TAT(process *arr, int n) {
    for (int i = 1; i <= n; i ++) {
        arr[i].tim[5] = arr[i].tim[2] + arr[i].tim[3];
    }
}

int main(void) {
    int n;

    printf ("Input the number of processes : ");
    scanf ("%d", &n);

    arr = (process*)malloc((n + 1) * 6 * sizeof(int));
    proces = (process*)malloc((n + 1) * 6 * sizeof(int));
    int order[] = {1, 2, 0, 3, 4, 5};


    printf ("Input the arrival time and burst time %d times : \n", n);
    for (int i = 1; i <= n; i ++) {
        arr[i].tim[0] = i;
        scanf("%d%d", &arr[i].tim[1], &arr[i].tim[2]);
        sift_up(i, order);
    }


    int count = n;
    while (count > 0) {
        arr[count] = delete_from_queue(&count, order);
    }
    for (int i = 1; i <= n; i ++) {
        proces[i] = arr[n - i + 1];
    }


    calculate_CT(proces, n);
    calculate_WT(proces, n);
    calculate_TAT(proces, n);


    double av_tt = 0, av_wt = 0;
    for (int i = 1; i <= n; i ++) {
        av_tt += proces[i].tim[5];
        av_wt += proces[i].tim[3];
    }
    print(proces, n);
    printf ("Average Turnaround time : %f\n", av_tt / n);
    printf ("Average Waiting time    : %f\n", av_wt / n);
    return EXIT_SUCCESS;
}



