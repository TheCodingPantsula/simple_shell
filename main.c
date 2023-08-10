#include "shell.h"
#include "builtins.h"

/**
 * main - checks if the shell is called
 *
 * Return: 0 on success(Always)
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		shell_interactive();
	}
	else
	{
		non_interactive_shell();
	}
	return (0);
}
