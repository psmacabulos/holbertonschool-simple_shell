#include "main.h"

/**
 * build_and_check_path - Builds and validates a full executable path
 * @directory: Directory from PATH (e.g. "/bin")
 * @command: Command name (e.g. "ls")
 *
 * Return: Newly allocated full path if executable, otherwise NULL
 */
char *build_and_check_path(char *directory, char *command)
{
	char *full_path;

	/*
	 * Allocate memory for "directory/command"
	 * +2 accounts for '/' and null terminator
	 */
	full_path = malloc(strlen(directory) + strlen(command) + 2);
	if (full_path == NULL)
		return (NULL);

	/* Build the full path */
	strcpy(full_path, directory);
	strcat(full_path, "/");
	strcat(full_path, command);

	/* Check if file exists and is executable */
	if (access(full_path, X_OK) == 0)
		return (full_path);

	/* Not executable or does not exist */
	free(full_path);
	return (NULL);
}
