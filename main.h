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

#endif /* MAIN_H */
