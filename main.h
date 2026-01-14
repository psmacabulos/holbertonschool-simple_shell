#ifndef MAIN_H
#define MAIN_H

/* Standard C libraries */
#include <stdio.h>      /* printf, perror, getline */
#include <stdlib.h>     /* malloc, free, exit */
#include <string.h>     /* strtok, strcmp, strlen */

/* UNIX system libraries */
#include <unistd.h>     /* fork, execve, access */
#include <sys/types.h>  /* pid_t */
#include <sys/wait.h>   /* wait, waitpid */
#include <errno.h>      /* errno */

/* Global environment variable */
extern char **environ;

/**
 * handle_input - Cleans and prepares user input
 * @input: Buffer returned by getline
 * @chars_read: Number of characters read by getline
 *
 * Return: Pointer to cleaned input, or NULL if empty
 */

char *handle_input(char *input, ssize_t chars_read);

#endif /* MAIN_H */

