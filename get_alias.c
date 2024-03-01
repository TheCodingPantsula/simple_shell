#include "shell.h"
#include "alias.h"

/**
 * get_alias_value - function to find value of an alias
 * @name: name of the alias
 * Return: value of alias, or NULL if alias doesnt exist
 */
char *get_alias_value(char *name)
{
	alias_t *alias = aliases;

	while (alias != NULL)
	{
		if (strcmp(alias->name, name) == 0)
		{
			return (alias->value);
		}
		alias = alias->next;
	}
	return (NULL);
}

/**
 * print_aliases - function to print all alliases
 */
void print_aliases(void)
{
	alias_t *alias = aliases;

	while (alias != NULL)
	{
		printf("%s='%s'\n", alias->name, alias->value);
		alias = alias->next;
	}
}
