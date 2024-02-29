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

extern char **environ;

#define BUFFER_SIZE 1024
#define MAX_PATH_LEN 1024
#define MAX_ARGS 64
#define TOKEN_BUFSIZE 64

int _childprocess(pid_t pid);
int _strcmp(char *str1, char *str2);
int run_commands(char **commands);
char **_token(char *str);
char *_strtok(char *str, const char *delim);
unsigned int _review_delim(char c, const char *delim);
char *_getline(void);
int exit_shell(char **argv);
int cd(char **argv);
char *load_path(char *cmd);
int runbuiltins_commands(char **argv, char *str);
int execute_commands(char **argv, char *str);
char *get_command_path(char *command);
void run_batch_mode(char **argv);
void print_error(int line_index, char **argv, int counter);
void run_interactive_made(char **argv);
int _runchildprocess(char **argv, char *str);
int env(char **args);
int set_env(char **args);
int unset_env(char **args);
char **split_line(char *line);
int read_from_buffer(char *buffer, int *buffer_len, int *buffer_pos);
#endif
