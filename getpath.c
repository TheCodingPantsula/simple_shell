#include "shell.h"

/**
 * get_command_path - get path of a command
 * @command: string of command
 * Return: NULL or full path
 */
char *get_command_path(char *command)
{
	char *path, *path_cpy, *dir, *file_path;
	int command_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
		path_cpy = strdup(path);
		dir = strtok(path_cpy, ":");
		while (dir != NULL)
		{
			command_len = strlen(command);
			dir_len = strlen(dir);
			file_path = malloc(command_len + dir_len + 2);
			strcpy(file_path, dir);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			if (stat(file_path, &buffer) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			free(file_path);
			dir = strtok(NULL, ":");
		}
		free(path_cpy);
		return (NULL);
}

