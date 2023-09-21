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
	char *line;
	size_t line_size;
	int line_st;

	(void)argc;
	(void)argv;

	line_size = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			my_prompt("$ ");
		signal(SIGINT, ctrl_c);
		line_st = getline(&line, &line_size, stdin);
		if (line_st == -1 || line_st == EOF)
			return (ctrl_d(line));

		my_exec(split_line(line), envp);
	}

	free(line);
	return (0);
}

/**
 * my_exec - main shell executer
 * @s_arr: Input, commands
 * @p_arr: Input, env
 * Reurn: none
 */

int my_exec(char **s_arr, char **p_arr)
{
	char *path, *command;

	if (s_arr == NULL || p_arr == NULL)
		return;
	/**
	 * all execution will happen here
	 */

	path = my_path(p_arr);
	if (my_built_in(s_arr, p_arr) == 0)
		return (0);

	if (my_fork() == 0)
	{
		if (s_arr[0][0] == '/')
		{
			if (access(s_arr[0], X_OK) == 0)
				execve(s_arr[0], s_arr, NULL);
			else
				perror("hsh/");
		}
		else
		{
			command = get_cmd_path(path_list(path), s_arr[0]);
			if (command == NULL)
				perror("full command");
			execve(command, s_arr, NULL);
		}
	}
	wait(NULL);
	return (0);
}
