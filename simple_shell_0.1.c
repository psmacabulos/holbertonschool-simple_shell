#include <stdio.h>      /* printf(), perror(), getline() */
#include <stdlib.h>     /* exit(), malloc(), free() */
#include <unistd.h>     /* fork(), execve() */
#include <sys/wait.h>   /* wait() */

/**
* main - Simple Shell 0.1
*
* Return: 0 on success, 1 on failure
*/

int main(void)
{
	/* define the parameter for getline */
	char *user_input = NULL;

	size_t input_size = 0;
	ssize_t chars_read;

	printf(">>> "); /* prompt */
	chars_read = getline(&user_input, &input_size, stdin);

	printf("You typed %s", user_input);

}
