#include "main.h"

/**
 * find_command_in_path - Finds a command in PATH directories
 * @command: Command name to search for
 *
 * Return: Full executable path if found, otherwise NULL
 */
char *find_command_in_path(char *command)
{
	char *path_value, *path_copy, *directory, *full_path;

	/* Get PATH from the environment */
	path_value = get_path_value();
	if (path_value == NULL)
		return (NULL);

	/* Duplicate PATH so strtok can modify it safely */
	path_copy = strdup(path_value);
	if (path_copy == NULL)
		return (NULL);

	/* Split PATH into directories separated by ':' */
	directory = strtok(path_copy, ":");
	while (directory != NULL)
	{
		/* Build "directory/command" and check if executable */
		full_path = build_and_check_path(directory, command);
		if (full_path != NULL)
		{
			free(path_copy);
			return (full_path);
		}
		directory = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
