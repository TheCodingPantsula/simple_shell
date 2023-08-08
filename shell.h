#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>

/* Macros */
#define TOK_DELIM " \t\r\n\a"
extern char **environ;

/* Prototypes */
void shell_interactive(void);
void non_interactive_shell(void);

/* Shell_interactive.c */
char *read_line(void);
char **split_line(char *line);
int runcommand(char **args);

/* runcommands */
int new_process(char **args);

/* Non_interactive_shell */
char *read_stream(void);

/* Builtis */
int my_cd(char **args);
int my_env(char **args);
int my_help(char **args);
int my_exit(char **args);

#endif
