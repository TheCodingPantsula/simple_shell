#include "shell.h"
#include "alias.h"

/**
 * handle_alias - function to handle alias command
 * @argv: arguments to alias command
 * Return: 0 on sucess
 */
int handle_alias(char **argv)
{
	int i;

	if (argv[1] == NULL)
	{
		print_aliases();
	}
	else
	{
		for (i = 1; argv[i] != NULL; i++)
		{
			char *name = argv[i];
			char *value = strchr(name, '=');

			if (value != NULL)
			{
				*value = '\0';
				value++;
				add_alias(name, value);
			}
			else
			{
				value = get_alias_value(name);
				if (value != NULL)
				{
					printf("%s='%s'\n", name, value);
				}
			}
		}
	}
	return (0);
}
