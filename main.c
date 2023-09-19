#include "shell.h"

/**
 * main - program entry point
 *
 * Return: always 0
 */
int main(void)
{
	char *input = NULL;

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
