#include "main.h"

/**
 * print_error - Prints command not found error message
 * @shell_name: Name of the shell (argv[0])
 * @line_number: Command line number
 * @command: Command that was not found
 */
void print_error(char *shell_name, unsigned long line_number,
		 char *command)
{
	char buffer[32];
	int length;

	write(STDERR_FILENO, shell_name, strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);

	length = snprintf(buffer, sizeof(buffer), "%lu", line_number);
	write(STDERR_FILENO, buffer, length);

	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, ": not found\n", 13);
}
