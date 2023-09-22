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
		clean_up(s_arr, line, new_line);
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
	char *command;
	pid_t my_pid;
	struct stat status;
	int pipe_fd[2];

	if (s_arr == NULL || p_arr == NULL)
		return (1);
	/**
	 * all execution will happen here
	 */

	if (my_built_in(s_arr, p_arr, str, new_str, l_count) == 1)
		return (0);

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
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
			my_execve_child(pipe_fd, s_arr[0], s_arr);
		}
		else
		{
			command = get_cmd_path(p_arr, s_arr[0]);
			if (command == NULL)
				my_error(s_arr, argv, str, new_str, l_count);
			my_execve_child(pipe_fd, command, s_arr);
		}
	}
	else
		my_execve_parent(pipe_fd);
	return (0);
}

void  my_execve_child(int pipe_fd[2], char *command, char **s_arr)
{
	close(pipe_fd[0]);

	dup2(pipe_fd[1], STDOUT_FILENO);
	execve(command, s_arr, NULL);

	perror("execve");
	exit(EXIT_FAILURE);	
}

void  my_execve_parent(int pipe_fd[2])
{
	char buffer[1024];
	ssize_t bytes_read;

	close(pipe_fd[1]);
	while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer))) > 0)
	{
		write(STDOUT_FILENO, buffer, bytes_read);
	}

	close(pipe_fd[0]);
	wait(NULL);
}
