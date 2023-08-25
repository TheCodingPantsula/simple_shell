#include "shell.h"


/**
 * read_from_buffer - read characters from buffer
 * @buffer: the buffer to read from
 * @buffer_len: the length of the buffer
 * @buffer_pos: the current position
 *
 * Return: the next character from the buffer, or -1 if the buffer is empy
 */
int read_from_buffer(char *buffer, int *buffer_len, int *buffer_pos)
{
	if (*buffer_pos >= *buffer_len)
	{
		*buffer_len = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		*buffer_pos = 0;
		if (*buffer_len <= 0)
		{
			return (-1);
		}
	}

	return (buffer[(*buffer_pos)++]);
}

/**
 * _getline - read a line from standard input
 * Return: pointer to the line read, or NULL on error
 */
char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_len;
	static int buffer_pos;
	char *line = NULL;
	int line_len = 0;
	int line_size = 0;
	char i;

	while (1)
	{
		i = read_from_buffer(buffer, &buffer_len, &buffer_pos);
		if (i == -1)
		{
			break;
		}

		if (line_len >= line_size)
		{
			line_size = line_size > 0 ? line_size * 2 : BUFFER_SIZE;
			line = realloc(line, line_size);
		}
		line[line_len++] = i;

		if (i == '\n')
		{
			break;
		}
	}

	if (line_len == 0)
	{
		free(line);
		return (NULL);
	}

	line[line_len] = '\0';
	return (line);
}
