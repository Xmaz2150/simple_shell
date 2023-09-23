#include "main.h"

/**
 * split_line - tokenizes str
 * @line: Input, str
 *
 *
 * Return: pointer to sub str's
 */
char **split_line(char *line)
{
	int i = 0;
	int t_count = 0;
	char **s_arr;
	char *str_tok, *t_copy;

	if (line == NULL)
		return (NULL);
	while (*(line + i) != '\0' || *(line + i) != '#')
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'
				       || line[i + 1] == '\t'))
			t_count++;
		i++;
	}

	i = 0;
	s_arr = malloc(sizeof(char *) * (t_count + 1));
	if (s_arr == NULL)
		return (NULL);
	str_tok = strtok(line, TOKKEN_DELIMS);
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

