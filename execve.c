#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(void)
{
    /* practice file to understand exeve*/
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		return (1);
	}
	else if (child_pid == 0)
	{
		extern char **environ;

		char *argv[] = {"/bin/echo", "I am learning execve", NULL};

		execve(argv[0], argv, environ);
	}
	else
    {
		wait(&status);
		printf("The child process has been finished and back to parent\n");
	}
}
