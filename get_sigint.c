#include "shell.h"

/**
 * get_sigint - function that handles the crtl + c call in prompt
 * @sig: input
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
