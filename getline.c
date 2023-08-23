#include "shell.h"

/**
 * _getline - reads a line from stdin
 * @buffer: pointer to the buffer
 * @size_t: pointer to the size of the buffer
 * @stream: pointer to the input stream
 *
 * Return: number of characters read, exclude terminate null byte,
 * or -1 if error occurs
 */
ssize_t _getline(char **buffer, size_t *buffer_size, FILE *stream)
{
	ssize_t buff_size = *buffer_size, len = 0;
	int character;
	char *new_buffer;

	/* Checks buffer, allocates memory and handle error */
	if (*bufffer = NULL)
	{
		buff_size = 128;
		*buffer = malloc(buff_size * sizeof(char));
		if (*buffer == NULL)
			return (-1);
	}

	while ((character = fgetc(stream)) != EOF)
	{
		/* Checks and resizes the buffer_size by doubling it */
		if (len >= buff_size - 1) /* if it can't handle the line, reallocate memory */
		{
			buff_size *= 2;
			new_buffer = realloc(*buffer, buff_size);
			if (new_buffer == NULL)
			{
				free(*buffer);
				return (-1);
			}
			*buffer = new_buffer;
		}

		(*buffer)[len++] = character;
		if (character == '\n')
			break;
	}
	if (len == 0 && character == EOF)
		return (-1);
	(*buffer)[len] = '\0';
	return (len);
}

