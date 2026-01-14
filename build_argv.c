#include "main.h"

/**
 * build_argv - Builds argument vector from command string
 * @cmd: Cleaned command string
 *
 * Return: NULL-terminated array of arguments
 */
char **build_argv(char *cmd)
{
	static char *argv[64]; /* make sure argv persist */
	int i = 0;

	argv[i] = strtok(cmd, " ");
	while (argv[i] != NULL && i < 63)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}

	return (argv);
}
