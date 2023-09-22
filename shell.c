#include "main.h"

/**
 * main - the shell
 * @ac: Input, argument count
 * @av: Input, arguments
 * @envp: Input, environmentt
 *
 * Return: 0 Always successs
 */
int main(int ac, char **av, char **envp)
{
	char *line, *new_line;
	size_t len = 0;
	ssize_t line_st;
	char **s_arr;
	int l_count = 0;

	(void)ac, (void)av;
	while (1)
	{
		line = NULL;
		len = 0;
		l_count++;
		if (isatty(STDIN_FILENO) == 1)
			my_prompt("$ ");
		signal(SIGINT, ctrl_c);
		line_st = getline(&line, &len, stdin);
		if (line_st == EOF || line_st == -1)
			return (ctrl_d(line));
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		new_line = str_realloc(line);
		if (new_line == NULL)
		{
			free(line);
			return (0);
		}
		s_arr = split_line(new_line);
		if (s_arr == NULL)
		{
			free(line);
			free(new_line);
			return (0);
		}
		my_exec(s_arr, envp, av, line, new_line, l_count);
		clean_up(line, new_line, s_arr);
	}
}

/**
 * my_exec - main shell executer
 * @arr: Input, commands
 * @env: Input, env
 * @av: Input, cl args
 * @s: Input, s
 * @n_s: Input, new realloced s
 * @l_cnt: Input, loop iterations
 *
 * Return: status
 */

int my_exec(char **arr, char **env, char **av, char *s, char *n_s, int l_cnt)
{
	pid_t my_pid;
	char *command;
	int signal;
	struct stat status;

	if (arr == NULL || *arr == NULL || av == NULL || *av == NULL)
		return (-1);
	if (env == NULL || *env == NULL)
		return (-1);
	if (my_built_in(arr, env, s, n_s, l_cnt) == 0)
		return (0);
	my_pid = fork();
	if (my_pid == -1)
	{
		write(STDOUT_FILENO, "Error forking", 13);
		return (-1);
	}
	if (my_pid == 0)
	{
		if (arr[0][0] == '/')
		{
			if (stat(arr[0], &status) == -1)
				my_error(av, arr, l_cnt, s, n_s);
			if (access(arr[0], X_OK) == -1)
				my_error(av, arr, l_cnt, s, n_s);
			execve(arr[0], arr, NULL);
		}
		else
		{
			command = get_cmd_path(arr[0], env);
			if (command == NULL)
				my_error(av, arr, l_cnt, s, n_s);
			else
				execve(command, arr, NULL);
		}
	}
	else
	{
		wait(&signal);
	}
	return (0);
}

