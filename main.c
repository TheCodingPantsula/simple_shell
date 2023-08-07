#include "shell.h"

/**
 * main - checks if the shell is called
 *
 * Return: 0 on success(Always)
 */
int main(void)
{
	// checks if the descriptor is associated with the termi
	if (isatty(STDIN_FILENO))
	{
		shell_interactive();
	}
	else
	{
		shell_no_interactive();
	}
	return (0);
}
