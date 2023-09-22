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
	int s1_len = 0;
	int s2_len = 0;
	char *new_str;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		*s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(sizeof(char));
		if (s2 == NULL)
			return (NULL);
		*s2 = '\0';
	}

	s1_len = _strlen(s1);
	s2_len = _strlen(s2);

	new_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_str == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}

	return (str_concat_helper(new_str, s1, s2));
}

/**
 * str_concat_helper - concats two strings
 * @new_str: Input, memory space to concat the strings
 * @s1: Input, str 1
 * @s2: Input, str 2
 *
 * Return: pointer to new_strd memory space
 */

char *str_concat_helper(char *new_str, char *s1, char *s2)
{
	int new_str_counter = 0;
	int str_counter = 0;

	while (*(s1 + str_counter) != '\0')
	{
		*(new_str + new_str_counter) = *(s1 + str_counter);
		new_str_counter++;
		str_counter++;
	}

	str_counter = 0;
	while (*(s2 + str_counter) != '\0')
	{
		*(new_str + new_str_counter) = *(s2 + str_counter);
		new_str_counter++;
		str_counter++;
	}
	*(new_str + new_str_counter) = '\0';
	return (new_str);
}

