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
			printf("$ ");
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
 * split_line - splits line to tokkens
 * @s: Input, line
 *
 * Return: string array
 */

char **split_line(char *s)
{
	char **s_arr = NULL;

	(void)s;
	/**
	 * string to be tokkenized here
	 */
	return (s_arr);
}

/**
 * my_exec - main shell executer
 * @s_arr: Input, commands
 *
 * Reurn: none
 */

void my_exec(char **s_arr)
{
	(void)s_arr;

	/**
	 * all execution will happen here
	 */
}
