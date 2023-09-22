#include "main.h"
/**
 * *_strdup- returns pointer to new string, dublicate of:
 * @str: Input
 *
 * Return: char(pointer)
 */
char *_strdup(char *str)
{
	int i;
	char *new_str;

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		new_str = malloc(sizeof(char) * _strlen(str) + 1);

		if (new_str == NULL)
		{
			return (NULL);
		}
		else
		{
			i = 0;

			while (str[i] != '\0')
			{
				new_str[i] = str[i];
				i++;
			}
		}
	}
	return (new_str);
}
