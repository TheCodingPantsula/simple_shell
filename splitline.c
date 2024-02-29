#include "shell.h"
#include <string.h>

#define MAX_ARGS 64

/**
 * split_line - split a command line itno arguments
 * @line: command line to split
 * Return: Array of arguments
 */
char **split_line(char *line)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	int arg_count = 0;
	int i, r;
	char *delim = " ";

	if (strstr(line, "&&") != NULL ||
			strstr(line, "||") != NULL ||
			strchr(line, ';') != NULL)
	{
		delim = "&&||;";
	}

	for (i = 0; line[i] != '\0'; i++)
	{
		while (strchr(delim, line[i]) != NULL)
		{
			i++;
		}
		if (line[i] == '\0')
		{
			break;
		}
		for (r = i; line[r] != '\0' && strchr(delim, line[r]) == NULL; r++)
		{}
		args[arg_count] = malloc(r - i + 1);
		strncpy(args[arg_count], &line[i], r - i);
		args[arg_count][r - i] = '\0';
		arg_count++;
		i = r;
	}

	args[arg_count] = NULL;
	return (args);
}
