#include "main.h"

#define PATH_LEN 1032

/**
 * my_built_in - shell buitins
 * @arr: Input, command and arguments
 * @env: Input, env
 * @line: Input, input
 * @new_line: Input, realloced input
 * @l_cnt: Input, loop i
 *
 * Return: status
 */

int my_built_in(char **arr, char **env, char *line, char *new_line, int l_cnt)
{
	if (arr == NULL || *arr == NULL)
		return (1);
	if (env == NULL || *env == NULL)
		return (1);
	if (_strcmp((arr[0]), "exit") == 0)
		return (my_exit(arr, line, new_line, l_cnt));
	else if (_strcmp((arr[0]), "cd") == 0)
		return (my_cd(arr, env));
	else if (_strcmp((arr[0]), "env") == 0)
		return (print_str_arr(env));
	else if (_strcmp((arr[0]), "setenv") == 0)
		return (my_set(arr));
	else if (_strcmp((arr[0]), "unsetenv") == 0)
		return (my_unset(arr));
	else
		return (1);
}

/**
 * my_exit - exit
 * @s_arr: Input, command and arguments
 * @line: Input, input
 * @new_line: Input, realloced input
 * @l_cnt: Input, loop i
 *
 * Return: status
 */

int my_exit(char **s_arr, char *line, char *new_line, int l_cnt)
{
	int num, j;
	char *cmd_num;

	j = 0;
	if (s_arr[1] == NULL)
	{
		clean_up(line, new_line, s_arr);
		exit(0);
	}
	else
	{
		num = _atoi(s_arr[1]);
		if (num == -1)
		{
			cmd_num = int_to_str(l_cnt);
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
	char *new_dir;
	char current_dir[PATH_LEN];

	if (s_arr[1] == NULL)
		new_dir = get_path("HOME", p_arr);
	else if (_strcmp(s_arr[1], "-") == 0)
		new_dir = get_path("OLDPWD", p_arr);
	else
		new_dir = s_arr[1];

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		exit(2);
	}
	if (setenv("OLDPWD", current_dir, 1) == -1)
	{
		perror("setenv");
		exit(2);
	}
	if (chdir(new_dir) == -1)
	{
		perror("chdir");
		exit(2);
	}
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		exit(2);
	}
	if (setenv("PWD", current_dir, 1) == -1)
	{
		perror("setenv");
		exit(2);
	}
	return (0);
}

