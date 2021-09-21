#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define N 20
#define true 1
#define false 0

typedef int bool;

int buffer[N];
bool filled = false, empty = true;
int count = 0;

void* producer(void *args) {
    printf ("Buffer contains : ");
    while (true) {
        if (filled) continue;
        int item = rand() % N;
        buffer[count] = item;
        printf ("%d ", buffer[count]);
        count ++;
        if (count >= N) filled = true;
        empty = false;
    }
    pthread_exit(0);
}

void* consumer(void *args) {
    printf ("Consumed from buffer : ");
    while (true) {
        if (empty) continue;
        count --;
        printf ("%d ", buffer[count]);
        if (count <= 0) {
            count = 0;
            empty = true;
        }
        filled = false;
    }
    pthread_exit(0);
}


int main(void) {
    pthread_t Prod, Cons;
    void *res;

    pthread_create(&Prod, NULL, producer, NULL);
    pthread_create(&Cons, NULL, consumer, NULL);

    pthread_join(Prod, &res);
    pthread_join(Cons, &res);

	return EXIT_SUCCESS;
}

