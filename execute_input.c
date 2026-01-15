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
	char *command;
	char **argument_list;
	int builtin_status;

	command = handle_input(user_input, strlen(user_input));
	if (command == NULL)
		return (0);

	argument_list = build_argv(command);
	if (argument_list == NULL || argument_list[0] == NULL)
		return (0);

	builtin_status = handle_builtins(argument_list);
	if (builtin_status != -1)
		return (builtin_status);

	return (launch_command(argument_list, shell_name, line_number));
}
