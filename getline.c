#include "shell.h"

/**
 * read_line - reads the line from stdin
 *
 * Return: pointer to a string with the line
 */
char *read_line(void)
{
	char *line;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else 
		{
			perror("error reading the line from stdin");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
