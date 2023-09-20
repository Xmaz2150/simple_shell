#include "main.h"

/**
 * free_arr - frees array of strings
 * @addr: Input, array
 *
 * Return: none
 */

void free_arr(char **addr)
{
	size_t i;

	i = 0;
	while (addr[i] != NULL)
	{
		free(addr[i]);
		i++;
	}
	free(addr[i]);
}


/**
 * my_built_in - shell buitins
 * @s_arr: Input, command and arguments
 * @p_arr: Input, env
 *
 * Return: status
 */

int my_built_in(char **s_arr, char **p_arr)
{
	if (s_arr == NULL)
		exit(EXIT_FAILURE);

	if (strcmp(s_arr[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (strcmp(s_arr[0], "env") == 0)
	{
		print_str_arr(p_arr);
		return (1);
	}
	else if (strcmp(s_arr[0], "cd") == 0)
	{
		chdir(s_arr[1]);
		return (1);
	}
	return (0);
}

/**
 * line_check - checks for readable chars
 * @s: Input, str to check for chars
 *
 * Return: status
 */

int line_check(char *s)
{
	int i;

	if (s == NULL)
		return (1);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 32 && s[i] <= 126)
			return (0);
	}
	return (1);
}
