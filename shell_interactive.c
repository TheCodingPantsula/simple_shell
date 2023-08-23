#include "shell.h"

/**
 * run_interactive_mode - run interactive commands
 * @argv: arguments
 * Return: void
 */
void run_interactive_mode(char **argv)
{
	char *buffer = NULL;
	char **argss = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("(prompt $) ");
		read = getline(&buffer, &len, stdin);

		if (read <= 0)
		{
			free(buffer);
			break;
		}

		if (read != EOF)
		{
			buffer[strcspn(buffer, "\n")] = '\0';
			if (strcmp(buffer, "exit") == 0)
				break;

			args = _token(buffer);
			runbuiltins_commands(args, argv[0]);
			free(args);
		}
	}
	free(buffer);
}
