#include "shell.h"

/**
 * _strtok - strings are seperated into tokens
 * @str: string
 * @delim: char delimeter
 * Return: pointer to the first token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *dup_str;
	char *res;

	if (!str)
		str = dup_str;

	if (!str)
		return (NULL);

	while (*str && _review_delim(*str, delim))
		str++;

	if (*str == '\0')
		return (NULL);

	res = str;

	while (*str && !_review_delim(*str, delim))
		str++;

	if (*str)
		*str++ = '\0';

	dup_str = str;

	return (res);
}

/**
 * _review_delim - check for delimination
 * @c: char
 * @delim: string
 * Return: (success) 1, otherwise 0
 */
unsigned int _review_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}

	return (0);
}
