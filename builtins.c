#include "shell.h"

/**
 * terminate_shell - terminates the shell
 * @argv: command instruction
 * Return: exits on 0 (Success)
 */
int terminate_shell(char **argv)
{
	int status = 0;

	if (argv[1] != NULL)
	{
		status = atoi(argv[1]);
	}
	exit(status);
}

/**
 * change_directory - switch from pwd
 * @argv: directory name to switch
 * Return: Exit on 1 (Success)
 */
int change_directory(char **argv)
{
	if (argv[1] == NULL)
	{
		fprintf(stderr, ": wrong argument\n");
		return (1);
	}

	if (chdir(argv[1]) != 0)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, "Can't find directory: %s\n", argv[1]);
		}
		else
		{
			perror("Can't find directory");
		}
		return (1);
	}
	return (0);
}
