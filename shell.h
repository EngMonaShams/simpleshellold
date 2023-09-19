#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define IN_SIZE 100

/*string functions*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);
void _puts(char *str);

/*exit finctions*/
void exit_shell(void);

void get_command(char **input);
void exec_fork(char *input);
char *cpy_input(char *input);
#endif /*SHELL_H*/
