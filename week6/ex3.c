#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

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

/// time = 0
/// last_run[] keeps the end of time of the last execution of the i'th process
/// calculates completion time and waiting time
void round_robin(int n, int quantum) {
    int cnt = 0, time = proces[1].tim[1];
    int rt[n + 1], last_run[n + 1];

    /// Assigning last_run[] and rt[], where rt is used to keep remaining time for i'th process to finish
    for (int i = 1; i <= n; i ++) {
        rt[i] = proces[i].tim[2];
        last_run[i] = proces[i].tim[1];
    }

    /// if time is smaller than arrival time it continues
    /// otherwise, it will check remained time for completion is bigger than quantum
    /// if yes, then execute i'th process in quantum
    /// otherwise, then execute i'th process till the end of the process
    while (cnt != n) {
        for (int i = 1; i <= n; i ++) {
            if (time < proces[i].tim[1] || rt[i] == 0) continue;
            if (rt[i] > quantum) {
                proces[i].tim[3] += time - last_run[i];
                time += quantum;
                rt[i] -= quantum;
            } else {
                proces[i].tim[3] += time - last_run[i];
                time += rt[i];
                rt[i] = 0;
                proces[i].tim[4] = time;
                cnt ++;
            }
            last_run[i] = time;
        }
    }
}


/// Calculate the Turnaround time
void calculate_TAT(process *arr, int n) {
    for (int i = 1; i <= n; i ++) {
        arr[i].tim[5] = arr[i].tim[2] + arr[i].tim[3];
    }
}



int main(void) {
    int n, quantum;

    printf ("Input the number of processes : ");
    scanf ("%d", &n);
    printf ("Input the quantum : ");
    scanf ("%d", &quantum);



    arr = (process*)malloc((n + 1) * 6 * sizeof(int));
    proces = (process*)malloc((n + 1) * 6 * sizeof(int));
    int order[] = {1, 0, 2, 3, 4, 5};

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


    round_robin(n, quantum);
    calculate_TAT(proces, n);
    print(proces, n);


    double av_tt = 0, av_wt = 0;
    for (int i = 1; i <= n; i ++) {
        av_tt += proces[i].tim[5];
        av_wt += proces[i].tim[3];
    }
    printf ("Average Turnaround time : %f\n", av_tt / n);
    printf ("Average Waiting time    : %f\n", av_wt / n);
    return EXIT_SUCCESS;
}



