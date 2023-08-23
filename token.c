#include "shell.h"

/**
 * _token - creates tokens from strings
 * @str: string
 * Return: arrays of strings
 */
char **_token(char *str)
{
	int i = 0;
	const char *delim = " \a\n\t\r";
	char *token;

	char **tokens = calloc(TOKEN_BUFSIZE, sizeof(char *));

	if (tokens == NULL)
	{
		fprintf(stderr, "error allocating memory\n");
		exit(1);
	}

	token = strtok(str, delim);

	while (token)
	{
		tokens[i] = token;
		i++;

		token = strtok(NULL, delim);
	}

	tokens[i] = NULL;

	return (tokens);
}
