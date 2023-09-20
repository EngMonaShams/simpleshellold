#include "shell.h"

/**
 * get_command - a function that get command from standard output
 * @input: pointer to string
 */
void get_command(char **input)
{
	size_t len = 0;
	int input_len;

	input_len = getline(input, &len, stdin);
	len = _strlen(*input);
	if (input_len > 265)
	{
		exit(0);
	}
	if (input_len == -1)
		exit_shell();
	if (len == 0)
		return;
	if (len > 0 && (*input)[len - 1] == '\n')
		(*input)[len - 1] = '\0';
}
