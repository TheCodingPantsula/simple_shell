#include "shell.h"

/**
 * unset_env - unset environment variable
 * @args: array of arguments
 */
void unset_env(char **args)
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
}
