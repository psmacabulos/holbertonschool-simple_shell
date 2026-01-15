#include "main.h"

/**
 * handle_builtins - Handles shell built-in commands
 * @argv: Argument vector
 *
 * Return:
 *   EXIT_SHELL if exit builtin
 *   0 if env builtin
 *   -1 if not a builtin
 */
int handle_builtins(char **argv)
{
	if (argv == NULL || argv[0] == NULL)
		return (-1);

	if (strcmp(argv[0], "exit") == 0)
		return (EXIT_SHELL);

	if (strcmp(argv[0], "env") == 0)
		return (print_env());

	return (-1);
}
