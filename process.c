#include "shell.h"

/**
 * _childprocess - function allows child process
 * @pid: process id
 * Return: returns status
 */
int _childprocess(void)
{
	int status;

	wait(&status);

	return (status);
}
