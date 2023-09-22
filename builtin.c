#include "main.h"


/**
 * my_built_in - shell buitins
 * @s_arr: Input, command and arguments
 * @p_arr: Input, env
 * @line: Input, input
 * @new_line: Input, realloced input
 * @l_count: Input, loop i
 *
 * Return: status
 */

int my_built_in(char **s_arr, char **p_arr, char *line, char *new_line, int l_count)
{
	if (s_arr == NULL || *s_arr == NULL)
		return (1);
	if (p_arr == NULL || *p_arr == NULL)
		return (1);
	if (_strcmp((s_arr[0]), "exit") == 0)
		return (my_exit(s_arr, line, new_line, l_count));
	else if (_strcmp((s_arr[0]), "cd") == 0)
		return (my_cd(s_arr, p_arr));
	else if (_strcmp((s_arr[0]), "env") == 0)
		return (print_str_arr(p_arr));
	else
		return (1);
}

/**
 * my_exit - exit
 * @s_arr: Input, command and arguments
 * @line: Input, input
 * @new_line: Input, realloced input
 * @l_count: Input, loop i
 *
 * Return: status
 */

int my_exit(char **s_arr, char *line, char *new_line, int l_count)
{
	int num, j;
	char *cmd_num;

	j = 0;
	if (s_arr[1] == NULL)
	{
		clean_up(line, new_line, s_arr);
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
			write(STDERR_FILENO, ": exit: Illegal number: ", 24);
			while (s_arr[1][j] != '\0')
				j++;
			write(STDOUT_FILENO, s_arr[1], j);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		clean_up(line, new_line, s_arr);
		_exit(num);
	}
}


/**
 * my_cd - cd builtin
 * @s_arr:  Input, s_arr of command str strings
 * @p_arr: Input, env variable
 *
 * Return: status
 */

int my_cd(char **s_arr, char **p_arr)
{
	int i = 0;
	char cwd[1024];
	char *newdir;

	if (s_arr[1] == NULL)
	{
		if (chdir(get_cmd_path("HOME", p_arr)) == -1)
		{
			perror(s_arr[0]);
			write(STDERR_FILENO, "cd: can't cd to home\n", 21);
		}
	}
	else
	{
		getcwd(cwd, 1024);
		while (cwd[i] != '\0')
			i++;
		cwd[i++] = '/';
		cwd[i] = '\0';
		newdir = str_concat(cwd, s_arr[1]);
		if (newdir == NULL)
			return (0);
		if (chdir(newdir) == -1)
		{
			perror(s_arr[0]);
			write(STDERR_FILENO, "can't cd into dir\n", 24);
		}
		free(newdir);
	}
	return (0);
}

