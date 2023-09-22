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
 *
 * Return: none
 */

void print_str_arr(char **s_arr)
{
	int i, len;

	for (i = 0; s_arr[i] != NULL; i++)
	{
		len = _strlen(s_arr[i]);
		write(STDOUT_FILENO, s_arr[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * my_error - error handling
 * @s_arr: Input, tokken arr
 * @str: Input, input
 * @new_str: Input, input realloced
 * @l_count: Input, shell iterations
 *
 * Return: none
 */
void my_error(char **s_arr, char **argv, char *str, char *new_str, int l_count)
{
	(void)l_count;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "No such file or directory\n", 26);
	clean_up(s_arr, str, new_str);
	exit(0);
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
	int i, t_count;
	char **s_arr, *str_tok, *t_copy;

	i = 0;
        t_count = 0;
	if (s == NULL)
		return (NULL);
	while (*(s + i) != '\0')
	{
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'
				       || s[i + 1] == '\t'))
			t_count++;
		i++;
	}

	i = 0;
	s_arr = malloc(sizeof(char *) * (t_count + 1));
	if (s_arr == NULL)
		return (NULL);
	str_tok = strtok(s, TOKKEN_DELIMS);
	while (str_tok != NULL)
	{
		t_copy = _strdup(str_tok);
		if (t_copy == NULL)
		{
			free(s_arr);
			return (NULL);
		}
		*(s_arr + i) = t_copy;
		str_tok = strtok(NULL, TOKKEN_DELIMS);
		i++;
	}
	*(s_arr + i) = NULL;
	return (s_arr);
}
