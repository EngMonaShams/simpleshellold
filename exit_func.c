#include "shell.h"

/**
 * exit_shell - afunction that exit shell safely
 */
void exit_shell(void)
{
	exit(0);
}

**
 * exit_alloc_error - afunction that exit shell safely
 */
void exit_alloc_error(void)
{
	perror("tsh: memory allocation error");
	exit(1);
}
