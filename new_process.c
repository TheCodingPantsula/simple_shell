#include "shell.h"

/**
 * new_process - creates anew process
 * @args: array of strings
 *
 * Return:  if success, otherwise 0
 */
int new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error in new_process: cheild process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in new_process: forking");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
