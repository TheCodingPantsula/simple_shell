#include "shell.h"

/**
 * runcommand - checks if command is a builtin or not
 * @args: command and flags
 *
 * Return: 1 on success, otherwise 0
 */
int runcommand(char **args)
{
	char *builtins_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*builtins_func[])(char **) = {
		&my_cd,
		&my_env,
		&my_help,
		&my_exit
	};
	size_t i = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; i < sizeof(builtins_func_list) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtins_func_list[i]) == 0)
		{
			return ((*builtins_func[i])(args));
		}
	}
	return (new_process(args));
}
