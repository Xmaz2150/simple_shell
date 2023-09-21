#include "main.h"

/**
 * clean_up - frees everything
 * @s_arr: Input, tokken arr
 * @str: Input, input
 * @new_str: Input, input realloced
 *
 * Return: none
 */

void clean_up(char **s_arr, char *str, char *new_str)
{
	free_arr(s_arr);
	free(str);
	free(new_str);
	free(s_arr);
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
