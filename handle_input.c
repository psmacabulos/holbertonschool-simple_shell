#include "main.h"

/**
 * handle_input - Cleans and prepares user input
 * @input: Buffer returned by getline
 * @chars_read: Number of characters read by getline
 *
 * Return: Pointer to cleaned command, or NULL if empty
 */
char *handle_input(char *input, ssize_t chars_read)
{
	char *start;
	char *end;

	if (input == NULL || chars_read <= 0)
		return (NULL);

	/* Remove trailing newline */
	if (input[chars_read - 1] == '\n')
		input[chars_read - 1] = '\0';

	/* Use a separate pointer to trim leading spaces */
	start = input;
	while (*start == ' ')
		start++;

	if (*start == '\0')
		return (NULL);

	/* Trim trailing spaces */
	end = start;
	while (*end)
		end++;

	end--;
	while (end > start && *end == ' ')
	{
		*end = '\0';
		end--;
	}

	return (start);
}
