#include "shell.h"

/**
 * _childprocess - allows function child process
 * @pid: process id
 * Return: child process returned
 */
int _childprocess(pid_t pid)
{
	int status;

	while (waitpid(pid, &status, 0) == -1)
	{
		if (errno != EINTR)
		{
			return (-1);
		}
	}

	return (status);
}
