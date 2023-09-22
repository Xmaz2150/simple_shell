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
		return (1);

	if (strcmp(s_arr[0], "exit") == 0)
		return (my_exit(s_arr, str, new_str, l_count));
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
 * my_exit - handles exit builtin
 * @s_arr: s_arr of strings commands for execution
 * @str: user input
 * @new_str: user input with new_str truncated
 * @l_count: no of commands entered by the user
 * Return: 0 on success, or exit code specified by user
 */
int my_exit(char **s_arr, char *str, char *new_str, int l_count)
{
	int num, j = 0;
	char *cmd_num;

	if (s_arr[1] == NULL)
	{
		clean_up(s_arr, str, new_str);
		exit(2);
	}
	else
	{
		num = _atoi(s_arr[1]);
		if (num == -1)
		{
			cmd_num = int_to_str(l_count);
			write(STDERR_FILENO, s_arr[0], 7);
			write(STDERR_FILENO, cmd_num, _strlen(cmd_num));
			write(STDERR_FILENO, ": exit: Invalid number: ", 24);
			while (s_arr[1][j] != '\0')
				j++;
			write(STDOUT_FILENO, s_arr[1], j);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		clean_up(s_arr, str, new_str);
		_exit(num);
	}
}

