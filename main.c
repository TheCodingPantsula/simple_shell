#include "shell.h"

void run_interactive_mode(char **argv);
void run_batch_mode(char **argv);

int exit_shell(char **argv);
int cd(char **argv);
int env(char **args);
int set_env(char **args);
int unset_env(char **args);

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
