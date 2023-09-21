#include "main.h"

/**
 * main - the shell
 * @argc: Input, argument count
 * @argv: Input, arguments
 * @envp: Input, environmentt
 *
 * Return: 0 Always successs
 */

int main(int argc, char **argv, char **envp)
{
	char *line, *new_line;
	size_t line_size = 0;
	ssize_t line_st;
	char **s_arr;
	int loop_count = 0;

	(void)argc, (void)argv;
	while (1)
	{
		line = NULL;
		line_size = 0;
		loop_count++;
		if (isatty(STDIN_FILENO) == 1)
			my_prompt("$ ");
		signal(SIGINT, ctrl_c);
		line_st = getline(&line, &line_size, stdin);
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
		my_exec(s_arr, envp, argv, line, new_line, loop_count);
	}
}
/**
 * my_exec - main shell executer
 * @s_arr: Input, commands
 * @p_arr: Input, env
 * @argv: Input, cl args
 * @str: Input, line
 * @new_str: Input, new realloced line
 * @l_count: Input, loop iterations
 *
 * Reurn: status
 */

int my_exec(char **s_arr, char **p_arr, char **argv, char *str, char *new_str, int l_count)
{
	char *path, *command;
	pid_t my_pid;
	struct stat status;
	my_list *paths;

	if (s_arr == NULL || p_arr == NULL)
		return (1);
	/**
	 * all execution will happen here
	 */

	if (my_built_in(s_arr, p_arr, str, new_str, l_count) == 1)
		return (0);

	my_pid = fork();
	if (my_pid == -1)
	{
		write(STDOUT_FILENO, "error forking", 13);
		return (1);
	}
	if (my_pid == 0)
	{
		if (s_arr[0][0] == '/')
		{
			if(stat(s_arr[0], &status) == -1)
				my_error(s_arr, argv, str, new_str, l_count);
			if (access(s_arr[0], X_OK) == -1)
				my_error(s_arr, argv, str, new_str, l_count);
			execve(s_arr[0], s_arr, NULL);
		}
		else
		{
			path = my_path(p_arr);
			if (path == NULL)
			{
				write(STDERR_FILENO, "PATH not found", 16);
				_exit(0);
			}
			paths = path_list(path);
			if (paths == NULL)
			{
				write(STDERR_FILENO, "PATH List err", 13);
				_exit(0);
			}
			command = get_cmd_path(path_list(path), s_arr[0]);
			if (command == NULL)
				my_error(s_arr, argv, str, new_str, l_count);
			execve(command, s_arr, NULL);
		}
	}
	else
		wait(NULL);
	return (0);
}
