#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
    /* practice file to understand fork */
	int status;

	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork failed");
		return (1);
	}

	else if (child_pid == 0)
	{


		printf("I am the child, PID=%d\n", getpid());
		return (42);
	}

	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			printf("Child exited with the code %d\n", WEXITSTATUS(status));
		}
		printf("I am the parent, child PID = %d and my PID = %d\n", child_pid, getpid());
	}
	return (0);
}
