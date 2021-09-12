#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	pid_t n = fork();
	if (n < 0) return EXIT_FAILURE;
	else if (n == 0) {
		printf ("Hello from child PID - %d , n = %d\n", getpid(), n);
	} else {
		printf ("Hello from parent PID - %d , n = %d\n", getpid(), n);
	}
	return EXIT_SUCCESS;
}

/*

After running this code 10 via shell script(ex1.sh), in command prompt appeared 20 lines, similar to 
"Hello from parent PID - getpid() , n = pidofChild"
"Hello from child PID - getpid() , n = 0"
When I first executed the shell script all lines were sorted by their pid numbers, parent process followed
by child process. In all these cases parent process was ready for execution first, and child process was second.

When I executed it second time, there were couple of lines, where first was child process
and second was parent process, but parent's pid number was smaller than child's pid number. In this case child
process was ready for execution first, parent process was second, despite the fact that parent process was
created first.

*/
