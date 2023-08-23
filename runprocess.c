#include "shell.h"

/**
 * _runchildprocess - run child process
 * @argv: array of arguments
 * @str: string program
 * Return: integer
 */
int _runchildprocess(char **argv, char *str)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		return (-1);
	}
	else if (pid == 0)
	{
		execute_commands(argv, str);
		perror(str);
		exit(1);
	}

	return (pid);
}
