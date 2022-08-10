#include "main.h"

/**
 * get_sigint - handles ctrl + c prompt
 * @sig: signal handler
 */

void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
