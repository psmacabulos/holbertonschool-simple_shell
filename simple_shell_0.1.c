#include "main.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0
 */
int main(void)
{
	char *user_input = NULL;
	char *command;
	size_t input_size = 0;
	ssize_t chars_read;
	pid_t child_id;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		chars_read = getline(&user_input, &input_size, stdin);
		if (chars_read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		command = handle_input(user_input, chars_read);
		if (command == NULL)
			continue;

		child_id = fork();
		if (child_id == -1)
			continue;

		if (child_id == 0)
		{
            char **argv;
            
            argv = build_argv(command);

			execve(argv[0], argv, environ);

			write(STDERR_FILENO,
			      "./shell: No such file or directory\n", 34);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}

	free(user_input);
	return (0);
}
