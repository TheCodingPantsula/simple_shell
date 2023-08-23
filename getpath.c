#include "shell.h"

/**
 * get_command_path - get path of a command
 * @command: string of command
 * Return: NULL or full path
 */
char *get_command_path(char *command)
{
	char *path, *path_cpy, *path_token, *file_path;
	int command_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_cpy = strdup(path);
		command_len = strlen(command);
		path_toekn = _strtok(path_cpy, ":");
		while (path_token != NULL)
		{
			dir_len = strlen(path_token);
			file_path = malloc(command_len + dir_len + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				file_path = NULL;
				path_token = _strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
