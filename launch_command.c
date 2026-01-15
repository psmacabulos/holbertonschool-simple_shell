#include "main.h"

/**
 * launch_command - Forks and executes an external command
 * @argument_list: Argument vector
 * @shell_name: Name of the shell
 * @line_number: Current line number
 *
 * Return: Exit status of the command
 */
int launch_command(char **argument_list, char *shell_name,
		   unsigned long line_number)
{
	pid_t child_id;
	int status = 0;
	char *resolved_path;

	resolved_path = resolve_command_path(argument_list[0],
					     shell_name,
					     line_number);
	if (resolved_path == NULL)
		return (127);

	child_id = fork();
	if (child_id == 0)
	{
		execve(resolved_path, argument_list, environ);
		print_error(shell_name, line_number, argument_list[0]);
		exit(127);
	}

	wait(&status);

	if (resolved_path != argument_list[0])
		free(resolved_path);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (0);
}
