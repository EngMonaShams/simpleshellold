#include "shell.h"

**
 * exit_alloc_error - afunction that exit shell safely
 */
void exit_alloc_error(void)
{
	perror("tsh: memory allocation error");
	exit(1);
}
