#include "shell.h"
#include "alias.h"

alias_t *aliases = NULL;

/**
 * add_alias - function to add new alias or update one
 * @name: name of the alias
 * @value: value of the alias
 */
void add_alias(char *name, char *value)
{
	alias_t *alias = aliases;
	alias_t *prev = NULL;

	while (alias != NULL)
	{
		if (strcmp(alias->name, name) == 0)
		{
			free(alias->value);
			alias->value = strdup(value);
		}
		prev = alias;
		alias = alias->next;
	}

	alias = malloc(sizeof(alias_t));
	alias->name = strdup(name);
	alias->value = strdup(value);
	alias->next = NULL;

	if (prev == NULL)
	{
		aliases = alias;
	}
	else
	{
		prev->next = alias;
	}
}
