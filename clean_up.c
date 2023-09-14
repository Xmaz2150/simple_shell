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
