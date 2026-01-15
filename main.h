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

extern char **environ;

/*
 * Input handling
 */
int read_input(char **user_input, size_t *input_size);
char *handle_input(char *input, ssize_t chars_read);

/* PATH handling */
char *get_path_value(void);

/*
 * Command execution
 */
void execute_input(char *user_input, char *shell_name,
		   unsigned long line_number);
char **build_argv(char *command);

/*
 * Error handling
 */
void print_error(char *shell_name, unsigned long line_number,
		 char *command);

#endif /* MAIN_H */
