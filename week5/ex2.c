#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

struct nthread {
	pthread_t threadId;
	int threadNum;
	char *str;
};

typedef struct nthread threadInfo;

void* job(void *args) {
	threadInfo *harg = (threadInfo*)args;
	printf ("%s = %d\n", harg -> str, harg -> threadNum);
	printf ("Thread ID : %lu\n\n", pthread_self());
}

int main(void) {
	int n;
	printf ("N = ");
	scanf ("%d", &n);
	threadInfo *tinfo;
	void *res;
	tinfo = calloc(n, sizeof(threadInfo));
	for (int i = 0; i < n; i ++) {
		tinfo[i].threadNum = i + 1;
		tinfo[i].str = "Hello from ";
	}
	for (int i = 0; i < n; i ++) {
		int check = pthread_create(&tinfo[i].threadId, NULL, job, (void *)&tinfo[i]);
		if (check == 0) continue;
		printf  ("Error\n");
		exit(EXIT_SUCCESS);
	}
	for (int i = 0; i < n; i ++) {
		int check = pthread_join(tinfo[i].threadId, &res);
		if (check == 0) {
            printf ("Thread %d is finished\n\n", i + 1);
            continue;
		}
		printf ("Error\n");
		exit(EXIT_SUCCESS);
	}
	pthread_exit(EXIT_SUCCESS);
	return EXIT_SUCCESS;
}

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
