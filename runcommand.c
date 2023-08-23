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
	int pid, status;
	char *builtin_commands[] = { "exit", "cd" };

	int numofbuiltins = sizeof(builtin_commands) / sizeof(char *);

	int (*builtin_functions[])(char **) = { &terminate_shell, &change_directory };

	if (argv[0] == NULL)
		return (0);

	for (count = 0; count < numofbuiltins ; count++)
	{
		if (_strcmp(argv[0], builtin_commands[count]) == 0)
			return ((*builtin_functions[count])(argv));
	}
	pid = _runchildprocess(argv, str);
	if (pid == -1)
		return (-1);
	status = _childprocess(pid);
	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}

	return (-1);
}
