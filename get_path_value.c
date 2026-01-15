#include "main.h"

/**
 * get_path_value - Retrieves the PATH environment variable value
 *
 * Return: Pointer to PATH value, or NULL if not found
 */
char *get_path_value(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}

	return (NULL);
}
