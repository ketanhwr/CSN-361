#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	for (int i = 0; i < 5; ++i) {
		fork();
	}

	printf("Process with PID=%d is exiting!\n", getpid());

	return 0;
}