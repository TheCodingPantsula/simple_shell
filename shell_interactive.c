#include "shell.h"

/**
 * run_interactive_mode - run interactive commands
 * @argv: arguments
 * Return: void
 */
void run_interactive_mode(char **argv)
{
	char *buffer = NULL;
	char **args = NULL;

	while (1)
	{
		printf("($) ");
		buffer = _getline();

		if (buffer == NULL)
		{
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';
		if (strcmp(buffer, "exit") == 0)
			break;

		args = _token(buffer);
		runbuiltins_commands(args, argv[0]);
		free(args);
		free(buffer);
	}
}
