#include "shell.h"

/**
 * _childprocess - function allows child process
 * Return: returns status
 */
int _childprocess(void)
{
	int status;

	wait(&status);

	return (status);
}
