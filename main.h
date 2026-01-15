#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Desc: Header file for simple shell project
 */

#include <stdio.h>      /* getline, snprintf */
#include <stdlib.h>     /* malloc, free, exit */
#include <string.h>     /* strtok, strlen */
#include <unistd.h>     /* fork, execve, write, isatty */
#include <sys/types.h>  /* pid_t */
#include <sys/wait.h>   /* wait */
#define EXIT_SHELL (-2)

extern char **environ;


/*
 * Input handling
 */
int read_input(char **user_input, size_t *input_size);
char *handle_input(char *input, ssize_t chars_read);

/* PATH handling */
char *get_path_value(void);
char *find_command_in_path(char *command);
char *build_and_check_path(char *directory, char *command);
char *resolve_command_path(char *command,
			   char *shell_name,
			   unsigned long line_number);


/*
 * Command execution
 */
int execute_input(char *user_input, char *shell_name,
		   unsigned long line_number);
char **build_argv(char *command);

/*
 * Error handling
 */
void print_error(char *shell_name, unsigned long line_number,
		 char *command);

#endif /* MAIN_H */
