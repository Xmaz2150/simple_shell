#include "main.h"

/**
 * *str_concat - returns pointer to new string containing :
 * @s1: Input and
 * @s2: Input
 *
 * Return: char
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, s1_len, s2_len;
	char *new_str;

	if ((s1 == NULL) && (s2 == NULL))
	{
		new_str = malloc(1);
		if (new_str == NULL)
			return (NULL);
		*new_str = '\0';
		return (new_str);
	}
	if (s1 == NULL)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(1);
		*s2 = '\0';
	}
	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	new_str = malloc(s1_len + s2_len + 2);
	if (new_str == NULL)
	{
		return (NULL);
	}
	else
	{
		for (i = 0 ; s1[i] != '\0'; i++)
			new_str[i] = s1[i];
		new_str[i] = '/';
		i++;
		for (j = 0 ; s2[j] != '\0'; j++)
			new_str[i + j] = s2[j];
		new_str[i + j] = '\0';
	}
	return (new_str);
}
