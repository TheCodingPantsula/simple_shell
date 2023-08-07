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

	// prompts symbol and tokenize line
	do {
		printf("shell_prompt$ ");
		line = read_line();
		args = split_line(line);
		status = execute_args(args);

		// frees memory
		free(line);
		free(args);
	} while (status == -1);

	exit(status);
}
