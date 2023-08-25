#include "shell.h"

/**
 * unset_env - unset environment variable
 * @args: array of arguments
 * Return: 0 (on success), otherwsise 1 if error occured
 */
int unset_env(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "unsetenv: not enough arguments\n");
		return;
	}

	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
	}
	return (0);
}
