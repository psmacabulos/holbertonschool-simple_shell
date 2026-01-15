#include "main.h"

/**
 * resolve_command_path - Resolves command path using direct or PATH lookup
 * @command: Command name
 * @shell_name: Shell name (argv[0])
 * @line_number: Current line number
 *
 * Return: Resolved executable path, or NULL on failure
 */
char *resolve_command_path(char *command,
			   char *shell_name,
			   unsigned long line_number)
{
	char *resolved_path;

	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == -1)
		{
			print_error(shell_name, line_number, command);
			return (NULL);
		}
		return (command);
	}

	resolved_path = find_command_in_path(command);
	if (resolved_path == NULL)
	{
		print_error(shell_name, line_number, command);
		return (NULL);
	}

	return (resolved_path);
}
