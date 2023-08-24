#include "shell.h"

/**
 * env - print the current environment
 * @args: array of arguments
 */
void env(char **args)
{
	int i;
	(void) args; /* To prevent unused parameter */

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
