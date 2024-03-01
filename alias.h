#ifndef ALIAS_H
#define ALIAS_H

#include <string.h>

typedef struct alias
{
	char *name;
	char *value;
	struct alias *next;
} alias_t;

extern alias_t *aliases;

void add_alias(char *name, char *value);
char *get_alias_value(char *name);
void print_aliases(void);
int handle_alias(char **argv);

#endif
