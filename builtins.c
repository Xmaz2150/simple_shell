#include "main.h"

/**
 * my_built_in - shell buitins
 * @s_arr: Input, command and arguments
 * @p_arr: Input, env
 *
 * Return: status
 */

int my_built_in(char **s_arr, char **p_arr, char *str, char *new_str, int l_count)
{
	(void)str;
	(void)new_str;
	(void)l_count;

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


