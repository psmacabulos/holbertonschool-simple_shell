#include "main.h"

/**
 * print_env - Prints the current environment
 *
 * Return: 0 on success
 */
int print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (0);
}
