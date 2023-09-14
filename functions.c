#include "main.h"

#define TOKKEN_BUF_SIZE 32
#define TOKKEN_DELIMS " \t\r\n\a"

/**
 * my_prompt - prints prompt to stdout
 * @str: Input, prompt
 *  Return: none
 */

void my_prompt(char *str)
{
	write(STDIN_FILENO, str, 2);
}

/**
 * print_str_arr - prints array of strings
 * @s_arr: Input, array
 * @arr_len: Input, no of arr elements
 *
 * Return: none
 */

void print_str_arr(char **s_arr, int arr_len)
{
	int i;

	for (i = 0; i < arr_len; i++)
	{
		printf("%s\n", s_arr[i]);
	}
}

/**
 * my_fork - creates new process
 *
 * Return: process id
 */

int my_fork(void)
{
	int pid;

	pid = fork();

	if (pid == -1)
		perror("error forking");
	return (pid);
}

/**
 * my_error - prints error
 * @s: Input, error message
 *
 * Return: none
 */

void my_error(char *s)
{
	(void)s;

	perror("Error");
}


/**
 * split_line - tokenizes str
 * @s: Input, str
 *
 *
 * Return: pointer to sub str's
 */

char **split_line(char *s)
{
	int arr_size, i;
	char **s_arr;
	char *str_tok;

	arr_size = TOKKEN_BUF_SIZE;
	i = 0;
	s_arr = malloc(arr_size * sizeof(char *));
	if (s_arr == NULL)
	{
		perror("allocation error :input");
		exit(98);
	}

	str_tok = strtok(s, TOKKEN_DELIMS);
	while (str_tok != NULL)
	{
		s_arr[i] = str_tok;
		i++;

		if (i >= arr_size)
		{
			arr_size += TOKKEN_BUF_SIZE;
			s_arr = realloc(s_arr, arr_size * sizeof(char *));
			if (s_arr == NULL)
			{
				perror("allocation error :tokken(s)");
				exit(99);
			}
		}

		str_tok = strtok(NULL, TOKKEN_DELIMS);
	}
	s_arr[i] = NULL;

	return (s_arr);
}
