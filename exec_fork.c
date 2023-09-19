#include "shell.h"

/**
 * cpy_input - a function that copy string to dynamic memory
 *
 * @input: pointer to input
 *
 * Return: pointer to copied string
 */

char *cpy_input(char *input)
{
	char *input_cpy = NULL;

	input_cpy = malloc(_strlen(input));
	if (input_cpy == NULL)
	{
		perror("tsh: memory allocation error");
		exit_shell();
	}
	_strcpy(input_cpy, input);
	return (input_cpy);
}

/**
 * tok_count - afunction that counts tokens
 *
 * @input: pointer to input
 *
 * Return: int
 */
int tok_count(char *input)
{
	char *token;
	int count = 1;

	token = strtok(input, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	return (count);
}

/**
 * exec_fork - a function that executes fork (child)
 *
 * @input: a pointer to input
 */
void exec_fork(char *input)
{
	char **args, *token, *input_cpy = NULL;
	int index = 0, tok_num;
	pid_t pid = fork();

	(void)input_cpy;

	if (pid == 0)
	{
		input_cpy = cpy_input(input);
		tok_num = tok_count(input);
		args = malloc(sizeof(char *) * tok_num);
		token = strtok(input_cpy, " ");
		while (token != NULL && index <= tok_num)
		{
			args[index] = malloc(_strlen(token));
			args[index++] = token;
			token = strtok(NULL, " ");
		}
		args[index] = NULL;
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error executing command");
			exit(1);
		}
		free(args);

	}
	else if (pid > 0)
		wait(NULL);
	else
	{
		perror("Error forking");
		exit(1);
	}
}
