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
	char *command;
	char *resolved_path;
	char **argument_list;

	command = handle_input(user_input, strlen(user_input));
	if (command == NULL)
		return;

	resolved_path = resolve_command_path(command, shell_name, line_number);
	if (resolved_path == NULL)
		return;

	child_id = fork();
	if (child_id == 0)
	{
		argument_list = build_argv(command);
		execve(resolved_path, argument_list, environ);
		print_error(shell_name, line_number, argument_list[0]);
		exit(EXIT_FAILURE);
	}
	else if (child_id > 0)
	{
		wait(NULL);
	}

	if (resolved_path != command) /* free only if it is dynamically allocated*/
		free(resolved_path);
}
