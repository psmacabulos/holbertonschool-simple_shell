#include "main.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0
 */
int main(void)
{
    char *user_input = NULL;
    size_t input_size = 0;
    ssize_t chars_read;
    pid_t child_id;

    while (1)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);

        chars_read = getline(&user_input, &input_size, stdin);
        if (chars_read == -1)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        if (user_input[chars_read - 1] == '\n')
            user_input[chars_read - 1] = '\0';

        child_id = fork();
        if (child_id == -1)
            continue;

        if (child_id == 0)
        {
            char *argv[2];

            argv[0] = user_input;
            argv[1] = NULL;

            execve(user_input, argv, environ);

            write(STDERR_FILENO,
                  "./shell: No such file or directory\n", 34);
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
        }
    }

    free(user_input);
    return (0);
}
