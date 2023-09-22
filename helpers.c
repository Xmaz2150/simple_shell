#include "main.h"

/**
 * *_strdup- returns pointer to new string, dublicate of:
 * @str: Input, str to dup
 *
 * Return: char(pointer)
 */
char *_strdup(char *str)
{
	int i = 0;
	int length = 0;
	char *string;

	if (str == NULL)
		return (NULL);

	while (*(str + i) != '\0')
	{
		length++;
		i++;
	}

	i = 0;
	string = malloc(sizeof(char) * length + 1);

	if (string == NULL)
		return (NULL);

	while (*(str + i) != '\0')
	{
		*(string + i) = *(str + i);
		i++;
	}
	*(string + i) = '\0';
	return (string);
}

/**
 * str_concat_helper - concats two strings
 * @new_str: Input, new memory space for strs the strings
 * @s1: Input, str 1
 * @s2: Input, str 2
 *
 * Return: cont str
 */

char *str_concat_helper(char *new_str, char *s1, char *s2)
{
	int n_str_counter = 0;
	int str_counter = 0;

	while (*(s1 + str_counter) != '\0')
	{
		*(new_str + n_str_counter) = *(s1 + str_counter);
		n_str_counter++;
		str_counter++;
	}

	str_counter = 0;
	while (*(s2 + str_counter) != '\0')
	{
		*(new_str + n_str_counter) = *(s2 + str_counter);
		n_str_counter++;
		str_counter++;
	}
	*(new_str + n_str_counter) = '\0';
	return (new_str);
}

/**
 * _strlen - calculates length of str
 * @s: Input
 * Return: len
 */

int _strlen(char *s)
{
	int len = 0;
	int i = 0;

	if (s == NULL)
		return (-1);

	while (s[i] != '\0')
	{
		len = len + 1;
		i++;
	}

	return (len);

}

/**
 * *str_concat - returns pointer to new string containing :
 * @s1: Input and
 * @s2: Input
 *
 * Return: char
 */
char *str_concat(char *s1, char *s2)
{
	int lengths1 = 0;
	int lengths2 = 0;
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

	lengths1 = _strlen(s1);
	lengths2 = _strlen(s2);

	new_str = malloc(sizeof(char) * (lengths1 + lengths2 + 1));
	if (new_str == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}

	return (str_concat_helper(new_str, s1, s2));
}

/**
 * _strcmp - compares two strings.
 * @s1: Input, str 1
 * @s2: Input, str 2
 *
 * Return: status
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}

	if ((*s1 == '\0') && (*s2 == '\0'))
		return (0);
	else if (*s1 > *s2)
		return ((int)(*s1 - *s2));
	else
		return ((int)(*s1 - *s2));
}
