#include "shell.h"

/**
 * run_commands - executes commands based on ;, &&,
 * and || operators
 * @commands: array of commands
 * Return: exit status of the last command executed
 */
int run_commands(char **commands)
{
	int status = 0;
	int i;
	char **argv;

	for (i = 0; commands[i] != NULL; i++)
	{
		argv = split_line(commands[i]);

		status = runbuiltins_commands(argv, commands[i]);
		free(argv);

		if ((strcmp(commands[i], "&&") == 0 && status != 0) || 
				(strcmp(commands[i], "||") == 0 && status == 0))
		{
			break;
		}
	}

	return (status);
}
