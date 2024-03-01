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
	char *builtin_commands[] = { "exit", "cd", "env", "setenv",
		"unsetenv", "alias" };

	int numofbuiltins = sizeof(builtin_commands) / sizeof(char *);

	int (*builtin_functions[])(char **) = { &exit_shell, &cd, &env,
		&set_env,
&unset_env, &handle_alias };

	if (argv[0] == NULL)
		return (0);

	for (count = 0; count < numofbuiltins; count++)
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

/**
 * run_commands - executes commands based on ;, &&, and ||
 * oparators
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
				(strcmp(commands[i], "||")
				 == 0 && status == 0))
		{
			break;
		}
	}

	return (status);
}
