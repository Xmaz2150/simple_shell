#include "main.h"

/**
 * main - the shell
 *
 * Return: 0 Always successs
 */

int main(void)
{
	char *line;
	size_t line_size;

	line_size = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			my_prompt("$ ");
			if (getline(&line, &line_size, stdin) == -1)
				exit(97);

			my_exec(split_line(line));
		}
		else
		{

			if (getline(&line, &line_size, stdin) == -1)
				exit(97);

			my_exec(split_line(line));

			break;
		}
	}

	free(line);
	return (0);
}

/**
 * my_exec - main shell executer
 * @s_arr: Input, commands
 *
 * Reurn: none
 */

void my_exec(char **s_arr)
{
	/**
	 * all execution will happen here
	 */

	if (my_fork() == 0)
	{
		if (execve(s_arr[0], s_arr, NULL) == -1)
			perror("hsh");
	}
	wait(NULL);
}
