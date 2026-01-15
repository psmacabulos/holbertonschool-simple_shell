#include "main.h"

/**
 * execute_input - Executes a single command line
 * @user_input: Raw input from stdin
 * @shell_name: Name of the shell (argv[0])
 * @line_number: Current line number
 *
 * Return: Exit status of the command
 */
int execute_input(char *user_input, char *shell_name,
		  unsigned long line_number)
{
	pid_t child_id;
	char *command, *resolved_path;
	char **argument_list;
	int status = 0;

	command = handle_input(user_input, strlen(user_input));
	if (command == NULL)
		return (0);

	argument_list = build_argv(command);
	if (argument_list == NULL || argument_list[0] == NULL)
		return (0);

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
	else if (child_id > 0)
	{
		wait(&status);
	}

	if (resolved_path != argument_list[0])
		free(resolved_path);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (0);
}
