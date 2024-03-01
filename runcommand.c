#include "shell.h"

/**
 * runbuiltins_commands - executes builtin commands
 * @argv: array of commands
 * @str: calls args
 * Return: 1 (on failure), otherwise runcommands
 */
int runbuiltins_commands(char **argv, char *str)
{
	int i;
	int last_exit_status = 0;
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

	for (i = 0; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '$')
		{
			if (strcmp(argv[i], "$?") == 0)
			{
				char exit_status_str[12];

				sprintf(exit_status_str, "%d", last_exit_status);
				argv[i] = strdup(exit_status_str);
			}
			else if (strcmp(argv[i], "$$") == 0)
			{
				char pid_str[12];

				sprintf(pid_str, "%d", getpid());
				argv[i] = strdup(pid_str);
			}
			else
			{
				char *value = getenv(argv[i] + 1);

				if (value != NULL)
				{
					argv[i] = value;
				}
			}
		}
	}

	pid = _runchildprocess(argv, str);
	if (pid == -1)
		return (-1);
	status = _childprocess(pid);
	if (WIFEXITED(status))
	{
		last_exit_status = WEXITSTATUS(status);
		return (last_exit_status);
	}

	return (-1);
}
