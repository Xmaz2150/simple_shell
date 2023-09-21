#include "main.h"
/**
 * free_arr - frees str array
 * @addr: Input, str array
 *
 * Return: none
 */

void free_arr(char **addr)
{
	int i = 0;

	while (addr[i] != NULL)
	{
		free(addr[i]);
		i++;
	}
	free(addr[i]);
}

/**
 * str_realloc - reallocates memory for char array
 * @str: Input, str to realloc
 * Return: pointer to new memory
 */
char *str_realloc(char *str)
{
	int i = 0;
	char *newstr;

	if (str == NULL)
		return (NULL);

	while (*(str + i) != '\n')
		i++;

	newstr = malloc(sizeof(char) * i + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (*(str + i) != '\n')
	{
		*(newstr + i) = *(str + i);
		i++;
	}
	*(newstr + i) = '\0';
	return (newstr);
}

/**
 * int_to_str - converts int to str
 * @n: Input, int
 * Return: str_int
 */

char *int_to_str(int n)
{
	int tens_int = n;
	char *int_str;
	int tens = 1;
	int i = 0;

	int_str = malloc(33);
	if (int_str == NULL)
		return (NULL);
	if (n == 0)
	{
		int_str[i] = 0 + '0';
		return (int_str);
	}
	n = n / 10;

	while (n != 0)
	{
		n = n / 10;
		tens *= 10;
	}

	while (tens != 0)
	{
		int_str[i] = (tens_int / tens) + '0';
		tens_int = tens_int % tens;
		tens /= 10;
		i++;
	}
	int_str[i] = '\0';
	return (int_str);
}

/**
 * free_list - frees  llist
 * @head: Input, head of the llist
 *
 * Return: none
 */

void free_list(my_list *head)
{
	my_list *next_node;

	while (head != NULL)
	{
		next_node = head->next;
		free(head->dir);
		free(head);
		head = next_node;
	}
}

/**
 * create_list - creates empty llist of
 * @str: Input, str
 *
 * Return: new llist
 */

my_list *create_list(char *str)
{
	int i = 0;
	int nodes = 1;
	my_list *node, *head, *tmp, *end;

	tmp = malloc(sizeof(my_list));
	if (tmp == NULL)
		return (NULL);
	head = tmp;

	end = malloc(sizeof(my_list));
	if (end == NULL)
	{
		free(tmp);
		return (NULL);
	}
	end->next = NULL;

	while (str[i] != '\0')
	{
		if (str[i] == ':')
			nodes++;
		i++;
	}

	while ((nodes - 2) > 0)
	{
		node = malloc(sizeof(my_list));
		if (node == NULL)
		{
			free(tmp);
			free(end);
			return (NULL);
		}
		tmp->next = node;
		tmp = tmp->next;
		nodes--;
	}
	tmp->next = end;
	return (head);
}
