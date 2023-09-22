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
 * @s_arr: Input, commands
 * @p_arr: Input, env
 * @argv: Input, cl args
 * @line: Input, line
 * @new_line: Input, new realloced line
 * @l_count: Input, loop iterations
 *
 * Reurn: status
 */

int my_exec(char **s_arr, char **p_arr, char **argv, char *line, char *new_line, int l_count)
{
	pid_t my_pid;
	char *command;
	int signal;
	struct stat status;

	if (s_arr == NULL || *s_arr == NULL || argv == NULL || *argv == NULL)
		return (-1);
	if (p_arr == NULL || *p_arr == NULL)
		return (-1);
	if (my_built_in(s_arr, p_arr, line, new_line, l_count) == 0)
		return (0);
	my_pid = fork();
	if (my_pid == -1)
	{
		write(STDOUT_FILENO, "Error forking", 13);
		return (-1);
	}
	if (my_pid == 0)
	{
		if (s_arr[0][0] == '/')
		{
			if (stat(s_arr[0], &status) == -1)
				my_error(argv, s_arr, l_count, line, new_line);
			if (access(s_arr[0], X_OK) == -1)
				my_error(argv, s_arr, l_count, line, new_line);
			execve(s_arr[0], s_arr, NULL);
		}
		else
		{
			command = get_cmd_path(s_arr[0], p_arr);
			if (command == NULL)
				my_error(argv, s_arr, l_count, line, new_line);
			else
				execve(command, s_arr, NULL);
		}
	}
	else
	{
		wait(&signal);
	}
	return (0);
}

