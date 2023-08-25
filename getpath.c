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
	if (path == NULL)
	{
		return (NULL);
	}
		path_cpy = strdup(path);
		dir = strtok(path_cpy, ":");
		while (dir != NULL)
		{
			command_len = strlen(cmd);
			dir_len = strlen(dir);
			full_path = malloc(command_len + dir_len + 2);
			strcpy(full_path, dir);
			strcat(full_path, "/");
			strcat(full_path, cmd);
			if (stat(full_path, &buffer) == 0)
			{
				free(path_cpy);
				return (full_path);
			}
			free(full_path);
			dir = strtok(NULL, ":");
		}
		free(path_cpy);
		return (NULL);
}

