#include "shell.h"

/**
 * shell_interactive - interpets the command line UNIX
 *
 * Return: void
 */
void shell_interactive(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("shell_prompt$ ");
		line = read_line();
		args = split_line(line);
		status = runcommand(args);
		free(line);
		free(args);
	} while (status == -1);

	exit(status);
}
