#include "shell.h"

/**
 * set_env - set environment variable
 * @args: array of arguments
 */
void set_env(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "setenv: not enough arguments\n");
		return;
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
	}
}
