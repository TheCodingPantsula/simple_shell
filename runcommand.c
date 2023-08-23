#include "shell.h"

/**
 * runbuiltins_commands - executes builtin commands
 * @argv: array of commands
 * @str: calls args
 * Return: 1 (on failure), otherwise runcommands
 */
int runbuiltins_commands(char **argv, char *str)
{
	int count;
	int pid, statuys;
	char *builtin_commands[] = { "exit", "cd" };

	int numofbuiltins = sizeof(builtin_commands) / sizeof(char *);

	int (*builtin_functions[])(char **) = { &terminate_shell, &change_directory };

	if (argv[0] == NULL)
		return (0);

	for (xcount = 0; count < numofbuiltins ; count++)
	{
		if (_strcmp(argv[0], builtin_commands[count]) == 0)
			return ((*builtin_functions[count])(argv));
	}
	pid = run_child_process(argv, str);
	if (pid == -1)
		return (-1);
	status = child_process(pid);
	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}

	return (-1);
}
