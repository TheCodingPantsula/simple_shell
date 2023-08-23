#include "shell.h"

/**
 * run_batch_mode - run batch commands
 * @argv: argument
 * Return: void
 */
void run_batch_mode(char **argv)
{
	char *buffer = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&buffer, &len, stdin)) != -1)
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}
		args = _token(buffer);
		runbuiltins_commands(args, argv[0]);
		free(args);
	}

	free(buffer);
}
