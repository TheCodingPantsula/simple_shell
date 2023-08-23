#include "shell.h"

/**
 * _childprocess - function allows child process
 * @pid: process id
 * Return: returns status
 */
int _childprocess(pid_t pid)
{
	int status;

	wait(&status);

	return (status);
}
