#include "shell.h"

/**
 * _getline - reads a line from stdin and stores it in a buffer
 *
 * @buffer: pointer to the buffer where line is stored.
 * @buff_size_ptr: pointer to the size of the buffer
 * @stream: pointer to the input stream
 *
 * Return: number of characters read, exclude terminate null byte,
 * or -1 if error occurs
 */
ssize_t _getline(char **buffer, size_t *buff_size_ptr, FILE *stream)
{
	ssize_t buff_size = *buff_size_ptr, len = 0;
	int character;
	char *new_buffer;

	/* Checks buffer, allocates memory and handle error */
	if (*buffer ==  NULL)
	{
		buff_size = 128;
		*buffer = malloc(buff_size * sizeof(char));
		if (*buffer == NULL)
			return (-1);
	}

	character = fgetc(stream);
	while (character != EOF)
	{
		/* Checks and resizes the buffer_size by doubling it */
		/* if it can't handle the line, realocate memory */
		if (len >= buff_size - 1)
		{
			buff_size *= 2;
			new_buffer = realloc(*buffer,
					buff_size);
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
		character = fgetc(stream);
	}
	if (len == 0 && character == EOF)
		return (-1);
	(*buffer)[len] = '\0';
	return (len);
}
