#include "main.h"

/**
 * my_set - sets env var
 * @s_arr: Input, args
 *
 * Return: status
 */
int my_set(char **s_arr)
{
	if (setenv(s_arr[1], s_arr[2], 1) == -1)
	{
		perror("setenv");
		return (1);
	}
	return (0);
}

/**
 * my_unset - unsets env var
 * @s_arr: Input, args
 *
 * Return: status
 */
int my_unset(char **s_arr)
{
	if (unsetenv(s_arr[1]) == -1)
	{
		perror("unsetenv");
		return (1);
	}
	return (0);
}

