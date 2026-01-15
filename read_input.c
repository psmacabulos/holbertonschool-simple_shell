#include "main.h"

/**
 * read_input - Reads a line from stdin
 * @user_input: Buffer for input
 * @input_size: Size of the buffer
 *
 * Return: 1 on success, 0 on EOF
 */
int read_input(char **user_input, size_t *input_size)
{
	ssize_t chars_read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);

	chars_read = getline(user_input, input_size, stdin);
	if (chars_read == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (0);
	}

	return (1);
}
