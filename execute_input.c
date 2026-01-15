#include "main.h"

/**
 * execute_input - Executes a single command line
 * @user_input: Raw input read from stdin
 * @shell_name: Name of the shell (argv[0])
 * @line_number: Current command line number
 */
void execute_input(char *user_input, char *shell_name,
		   unsigned long line_number)
{
	pid_t child_id;
	char *command;
	char **argument_list;

	command = handle_input(user_input, strlen(user_input));
	if (command == NULL)
		return;

	/*
	 * Step 1 (Shell 0.3):
	 * If command contains '/', check it directly without using PATH
	 */
	if (strchr(command, '/') && access(command, X_OK) == -1)
	{
		print_error(shell_name, line_number, command);
		return;
	}

	child_id = fork();
	if (child_id == 0)
	{
		argument_list = build_argv(command);
		execve(argument_list[0], argument_list, environ);
		print_error(shell_name, line_number, argument_list[0]);
		exit(EXIT_FAILURE);
	}
	else if (child_id > 0)
	{
		wait(NULL);
	}
}
