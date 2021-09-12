#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	for (int i = 1; i <= 5; i ++) {
		fork();
		sleep(5);
	}
	return EXIT_SUCCESS;
}

/*

There 8 processes were created

1 --- 2 --- 4 --- 8
   |     |
   |     -- 7
   |
   -- 3 --- 6
   |
   -- 5

1) When program runs 1'st process is created, and when fork() command  is executed it creates 2'nd process.

2) And 1'st process reaches second fork(), and it creates 3'rd process, simultaneously(quasi-parallel) 2'nd process
reaches second fork(), and it also creates 4'th process.

3) Again 1'st process reaches third fork(), and it creates 5'th process, simultaneously(quasi-parallel) 3'rd
process reaches  third fork(), and it creates 6'th process, simultaneously(quasi-parallel) 2'nd process reaches 
third fork(), and it creates 7'th process, simultaneously(quasi-parallel) 4'th process reaches third fork(), 
and it creates 8'th process.

When fork() was called 5 times, 32 processes were created.

*/
