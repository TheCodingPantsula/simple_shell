#include "shell.h"

/**
 * runcommand - checks if command is a builtin or not
 * @args: command and flags
 *
 * Return: 1 on success, otherwise 0
 */
int runcommand(char **args)
{
	char *builtins[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*builins[])(char **) = {
		&my_cd,
		&my_env,
		&my_help,
		&my_exit
	};
	int i;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (i = 0; i < sizeof(builtins) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtins[i]) == 0)
		{
			return ((*builtins[i])(args));
		}
	}
	return (new_process(args));
}
