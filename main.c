#include "shell.h"

/**
 * main - program entry point
 *
 * @ac: number of args
 * @args:pointer to array of args
 *
 * Return: always 0
 */
int main(int ac, char **args, char **env)
{
	char *input = NULL, *trim_input;

	(void)ac, (void)args;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			write(STDOUT_FILENO, "shell$", _strlen("shell$"));
			fflush(stdout);
		}
		get_command(&input);
		_strcpy(trim_input, input);
		while (*trim_input == ' ' || *trim_input == '\t')
			trim_input++;
		if (*trim_input == '\0')
		{
			free(input);
			exit(0);
		}
		exec_fork(input, env);
		free(input);
		input = NULL;
	}
	return (0);
}
