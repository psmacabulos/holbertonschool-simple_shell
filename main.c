#include "main.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	char *user_input = NULL;
	size_t input_size = 0;
	unsigned long line_number = 0;
	int last_status = 0;

	(void)argc;

	while (read_input(&user_input, &input_size))
	{
		line_number++;
		last_status = execute_input(user_input, argv[0], line_number);

		if (last_status == EXIT_SHELL)
		{
			last_status = 0;
			break;
		}
	}

	free(user_input);
	exit(last_status);
}
