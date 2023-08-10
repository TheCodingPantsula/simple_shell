#include "shell.h"

/**
 * own_cd - changs the current working directory
 * @args: commands and flags
 *
 * Return: 1 on success, otherwise 0
 */
int own_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "own_cd: expected arguments to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("own_cd");
		}
	}
	return (1);
}
/**
 * own_env - prints the environment variables
 * @args: commands and flags
 *
 * Return: 1 on success, otherwise 0
 */
int own_env(char **args)
{
	int i;
	(void) args;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (1);
}
/**
 * own_help - displays help information for shell commands
 * @args: commands and flags
 *
 * Return: 1 on success, otherwise 0
 */
int own_help(char **args)
{
	(void) args;
	printf("Type, and hit enter.\n");
	printf("Built in:\n");

	printf(" cd\n");
	printf(" env\n");
	printf(" help\n");
	printf(" exit\n");

	return (1);
}
/**
 * own_exit - exits the shell
 * @args: commands and flags
 *
 * Return: 1 on success, otherwise 0
 */
int own_exit(char **args)
{
	(void) args;
	return (0);
}
