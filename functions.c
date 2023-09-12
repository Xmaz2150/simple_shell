#include "main.h"

/**
 * my_fork - creates new process
 *
 * Return: process id
 */

int my_fork(void)
{
	int pid;

	pid = fork();

	if (pid == -1)
		perror("error forking");
	return (pid);
}

/**
 * my_error - prints error
 * @s: Input, error message
 *
 * Return: none
 */

void my_error(char *s)
{
	(void)s;

	perror("Error");
}
