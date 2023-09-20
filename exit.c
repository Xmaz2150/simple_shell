#include "main.h"

/**
 * ctrl_c - prihibits exit with ctrl + d
 * @signum: Input, signum
 *
 * Return: none
 */

void ctrl_c(int signum)
{
	(void)signum;

	write(STDOUT_FILENO, "\n$ ", 3);
}
