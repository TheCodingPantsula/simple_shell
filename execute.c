#include "shell.h"

char *load_path(char *cmd);

/**
 * execute_commands - execute the commands
 * @argv: array of commands (parameters)
 * @str: string of names
 * Return: 0 success
 */
int execute_commands(char **argv, char *str)
{
	int status;

	status = execve(argv[0], argv, NULL);

	if (status == -1)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", str, errno, argv[0]);
			fflush(stderr);
			exit(127);
		}
		else
			perror("execve");
		exit(1);
	}
	return (status);
}
