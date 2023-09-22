#include "main.h"

/**
 * _atoi - converts a string into an integer
 * @s: Input, string to convert to integer
 * Return: new int
 */
int _atoi(char *s)
{
	int i, j, tens, is_neg, neg_num, pos_num;
	unsigned int integer;

	i = 0; 
	j = 0;
	tens = 1;
	is_neg = 0;
	neg_num = 0;
	pos_num = 0;
	integer = 0;

	while (s[j] != '\0')
	{
		if (s[j] > '9' || s[j] < '0')
			return (-1);
		j++;
	}
	while ((s[i] > '9' || s[i] < '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			neg_num++;
		if (s[i] == '+')
			pos_num++;
		i++;
	}
	if (s[i] == '\0')
		return (0);

	if ((neg_num % 2) != 0)
		is_neg = 1;

	tens = tens_multiplier(i, s);
	while (s[i] >= '0' && s[i] <= '9')
	{
		integer += ((s[i] - '0') * tens);
		tens /= 10;
		i++;
	}
	if (is_neg == 1)
		integer *= -1;

	return ((int) integer);
}
/**
 * tens_multiplier - funct to finds mult factor of ten
 * @pos: Input, index number in string
 * @s: Input, string pointer
 *
 * Return: tens multiplier
 */

int tens_multiplier(int pos, char *s)
{
	double tens = 1;

	while (s[pos] >= '0' && s[pos] <= '9')
	{
		tens *= 10;
		pos++;
	}

	tens /= 10;
	return ((int) tens);
}

