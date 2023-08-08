#include "shell.h"

/**
 * read_stream - reads a line from the stream
 *
 * Return: pointer that points the read line
 */
char *read_stream(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
