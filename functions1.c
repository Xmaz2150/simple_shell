#include "main.h"


/**
 * print_str_arr - prints array of strings
 * @s_arr: Input, array
 *
 * Return: none
 */
int print_str_arr(char **s_arr)
{
	int i = 0, length = 0;

	while (s_arr[i] != NULL)
	{
		length = _strlen(s_arr[i]);
		write(STDOUT_FILENO, s_arr[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
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

/**
 * _atoi - converts a string into an integer
 * @s: Input, string to convert to integer
 * Return: new int
 */
int _atoi(char *s)
{
	int i, j = 0;
	int tens = 1;
	unsigned int integer = 0;
	int is_neg = 0;
	int neg_num = 0;
	int pos_num = 0;

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
 * int_to_str - converts int to str
 * @n: Input, int
 * Return: str_int
 */
char *int_to_str(int n)
{
	int tensint = n;
	char *integer;
	int tens = 1;
	int i = 0;

	integer = malloc(33);
	if (integer == NULL)
		return (NULL);
	if (n == 0)
	{
		integer[i] = 0 + '0';
		return (integer);
	}
	n = n / 10;

	while (n != 0)
	{
		n = n / 10;
		tens *= 10;
	}

	while (tens != 0)
	{
		integer[i] = (tensint / tens) + '0';
		tensint = tensint % tens;
		tens /= 10;
		i++;
	}
	integer[i] = '\0';
	return (integer);
}
