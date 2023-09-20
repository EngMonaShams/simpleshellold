#include "shell.h"

/**
 * mk_path -  afunction that return full path for command
 *
 * @cmd: pointer to command
 *
 * Return: pointer to path
 */
char *mk_path(char *cmd)
{
	char *path, *path_cpy, *cmd_path, *token;
	int len_cmd, len_tok;
	struct stat buf;

	path = getenv("PATH");
	if (path)
	{
		path_cpy = _strdup(path);
		len_cmd = _strlen(cmd);
		token = strtok(path_cpy, ":");
		while (token != NULL)
		{
			len_tok = _strlen(token);
			cmd_path = malloc(len_cmd + len_tok + 2);
			_strcpy(cmd_path, token);
			_strcat(cmd_path, "/");
			_strcat(cmd_path, cmd);
			_strcat(cmd_path, "\0");

			if (stat(cmd_path, &buf) == 0)
			{
				free(path_cpy);
				return (cmd_path);
			}
			else
			{
				free(cmd_path);
				token = strtok(NULL, ":");
			}
		}
			free(path_cpy);
			free(cmd_path);
			if (stat(cmd, &buf) == 0)
				return (cmd);
			return (NULL);
	}
	return (NULL);
}

