#include "main.h"

/**
 * free_arr - frees array of strings
 * @addr: Input, array
 *
 * Return: none
 */

void free_arr(char ***addr)
{
	size_t i;

	i = 0;
	while (*addr[i] != NULL)
	{
		free(*addr[i]);
		i++;
	}
	free(*addr);
}

/**
 * my_built_in - shell buitins
 * @s_arr: Input, command and arguments
 *
 * Return: none
 */

void my_built_in(char **s_arr)
{
	if (s_arr == NULL)
		exit(EXIT_FAILURE);

	if (strcmp(s_arr[0], "exit") == 0)
		exit(EXIT_SUCCESS);
}
