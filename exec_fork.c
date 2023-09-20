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

	input_cpy = malloc(_strlen(input) + 1);
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
	int count = 0;

	token = strtok(input, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	count++;
	return (count);
}

/**
 * exec_fork - a function that executes fork (child)
 *
 * @input: a pointer to input
 */
void exec_fork(char *input)
{
	char **args, *token, *input_cpy = NULL, *cmd;
	int index = 0, tok_num;
	pid_t pid;

	input_cpy = cpy_input(input);
	tok_num = tok_count(input);
	args = malloc(sizeof(char *) * tok_num);
	token = strtok(input_cpy, " ");
	while (token != NULL && index <= tok_num)
	{
		args[index] = malloc(_strlen(token) + 1);
		args[index++] = token;
		token = strtok(NULL, " ");
	}
	args[index] = NULL;
	if (!_strcmp(args[0], "exit"))
		exit(0);
	pid = fork();
	if (pid == 0)
	{
		cmd = mk_path(args[0]);
		if (execve(cmd, args, NULL) == -1)
		{
			perror("Error executing command");
			exit(1);
		}
		free(cmd);
	}
	else if (pid > 0)
		wait(NULL);
	else
	{
		perror("Error forking");
		exit(1);
	}
	free(args);
	free(input_cpy);
}
