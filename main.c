#include "shell.h"

/**
 * main - program entry point
 *
 * Return: always 0
 */
int main(int ac, char **args)
{
	char *input = NULL;

	(void)ac, (void)args;

	while (1)
	{
		write(STDOUT_FILENO, "shell$", _strlen("shell$"));
		get_command(&input);
		exec_fork(input);
		free(input);
		input = NULL;
	}
	return (0);
}
