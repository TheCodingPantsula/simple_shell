#include "shell.h"

/**
 * exit_shell - terminates the shell
 * @argv: command instruction
 * Return: exits on 0 (Success)
 */
int exit_shell(char **argv)
{
	int status = 0;

	if (argv[1] != NULL)
	{
		status = atoi(argv[1]);
	}
	exit(status);
}

/**
 * cd - switch from pwd
 * @argv: directory name to switch
 * Return: Exit on 1 (Success)
 */
int cd(char **argv)
{
	char *dir;
	char cwd[1024];

	if (argv[1] == NULL)
	{
		dir = getenv("Home");
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		dir = getenv("Oldpwd");
	}
	else
	{
		dir = argv[1];
	}

	if (chdir(dir) == -1)
	{
		perror("cd");
	}
	else
	{
		setenv("Oldpwd", getenv("pwd"), 1);
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			setenv("pwd", cwd, 1);
		}
	}
	return (0);
}
