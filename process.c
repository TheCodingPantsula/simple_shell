#include "shell.h"

/**
 * _childprocess - function allows child process
 * @pid: process ID of the child process
 * Return: returns status
 */
int _childprocess(pid_t pid)
{
	int status;

	waitpid(pid, &status, 0);

	return (status);
}
