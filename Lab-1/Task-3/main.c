#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	pid_t pid = fork();
	if (pid < 0) {
		printf("Process could not be created!\n");
		exit(0);
	}

	printf("Process ID: %d\n", pid);

	return 0;
}