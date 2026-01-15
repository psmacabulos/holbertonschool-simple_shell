#include "main.h"

/**
 * execute_input - Executes a single command line
 * @user_input: Raw input from stdin
 * @shell_name: Name of the shell (argv[0])
 * @line_number: Current line number
 */
void execute_input(char *user_input, char *shell_name,
		   unsigned long line_number)
{
	pid_t child_id;
	char *command, *resolved_path;
	char **argument_list;

	command = handle_input(user_input, strlen(user_input));
	if (command == NULL)
		return;

	argument_list = build_argv(command);
	if (argument_list == NULL || argument_list[0] == NULL)
		return;

	resolved_path = resolve_command_path(argument_list[0],
					     shell_name,
					     line_number);
	if (resolved_path == NULL)
		return;

	child_id = fork();
	if (child_id == 0)
	{
		execve(resolved_path, argument_list, environ);
		print_error(shell_name, line_number, argument_list[0]);
		exit(EXIT_FAILURE);
	}
	else if (child_id > 0)
	{
		wait(NULL);
	}

	if (resolved_path != argument_list[0])
		free(resolved_path);
}
