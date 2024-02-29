#include "shell.h"

/**
 * _childprocess - function allows child process
 * @pid: process ID of the child process
 * Return: returns status
 */
int _childprocess(pid_t pid)
{
	int status;

	do {
		waitpid(pid, &status, WUNTRACED | WCONTINUED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	return (status);
}
