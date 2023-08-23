#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
#include <stddef.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int _childprocess(pid_t pid);
int _strcmp(char *str1, char *str2);
char **_token(char *str);
char *_strtok(char *str, const char *delim);
unsigned int _review_delim(char c, const char *delim);
ssize_t _getline(char **buffer, size_t *buff_size_ptr, FILE *stream);
int terminate_shell(char **argv);
int change_directory(char **argv);
int runbuiltins_commands(char **argv, char *str);
int execute_commands(char **argv, char *str);
int *get_command_path(char *command);
char *get_command_path(char *command);
void run_batch_mode(char **argv);
void run_interactive_made(char **argv);
int _runchildprocess(char **argv, char *str);
#endif
