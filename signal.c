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

/**
 * ctrl_d - frees str when ctrl + d
 * @str: Input, buffer
 *
 * Return: int succesful termination
 */
int ctrl_d(char *input)
{
	free(input);
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
