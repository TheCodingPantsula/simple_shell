#include "shell.h"


/**
 * main - entry point of program
 * @argc: argument counter
 * @argv: vector pointer
 * Return: 0 (On success), otherwise 1
 */
int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		printf("Usage: %s\n", argv[0]);
		return (1);
	}
	if (isatty(STDIN_FILENO))
	{
		run_interactive_mode(argv);
	}
	else
	{
		run_batch_mode(argv);
	}
	return (0);
}
