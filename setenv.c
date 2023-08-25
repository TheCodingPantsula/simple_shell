#include "shell.h"

/**
 * set_env - set environment variable
 * @args: array of arguments
 * Return: 0 (on success), otherwise 1 if error occured
 */
int set_env(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "setenv: not enough arguments\n");
		return (0);
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
	}
	return (0);
}
