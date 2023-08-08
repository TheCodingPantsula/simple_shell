#include "shell.h"
#define BUFFER_SIZE 1024

/**
 * non_interactive_shell - interprets the command line unix
 *
 * Return: void
 */
void non_interactive_shell(void)
{
	char *line;
	char **args;
	int status;
	
	do {
		fgets(line, BUFFER_SIZE, stdin);
		args = split_line(line);
		status = runcommand(args);
		free(args);
	} while (status == -1);

	exit(status);
}
	
