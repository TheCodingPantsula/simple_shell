#include "shell.h"

/**
 * exit_shell - terminates the shell
 * @argv: command instruction
 * Return: exits on 0 (Success)
 */
int exit_shell(char **argv)
{
	int status = atoi(argv[1]);

	if (argv[1] == NULL || argv[2] != NULL)
	{
		fprintf(stderr, "Usage: exit [exit_status]\n");
		return (1);
	}

	exit(status);
}

/**
 * cd - switch from pwd
 * @argv: directory name to switch
 * Return: Exit on 1 (Success)
 */
int cd(char **argv)
{
	char *dir;

	if (argv[1] == NULL){
		dir = getenv("HOME");
	} else if (strcmp(argv[1], "-") = 0) {
		dir = getenv("OLDPWD");
	} else {
		dir = argv[1];
	}

	if (chdir(dir) == -1) {
		prerror("cd");
		return (1);
	}

	setenv("OLDPWD", getenv("PWD"), 1);
	if (getcwd(getenv("PWD"), sizeof(getenv("PWD"))) == NULL) {
		perror("getcwd");
		return (1);
	}

	return (0);

}
