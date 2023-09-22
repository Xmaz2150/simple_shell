#include "main.h"

/**
 * str_realloc - reallocates memory for char array
 * @str: Input, str to realloc
 * Return: pointer to new memory
 */
char *str_realloc(char *str)
{
	int i = 0;
	char *new_str;

	if (str == NULL)
		return (NULL);

	while (*(str + i) != '\n')
		i++;

	new_str = malloc(sizeof(char) * i + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (*(str + i) != '\n')
	{
		*(new_str + i) = *(str + i);
		i++;
	}
	*(new_str + i) = '\0';
	return (new_str);
}

/**
 * free_list - frees  llist
 * @head: Input, head of the llist
 *
 * Return: none
 */

void free_list(my_list *head)
{
	my_list *nextnode;

	while (head != NULL)
	{
		nextnode = head->next;
		free(head->dir);
		free(head);
		head = nextnode;
	}
}

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
 * clean_up - frees everything
 * @line: Input, input
 * @new_line: Input, input realloced
 * @s_arr: Input, tokken arr
 *
 * Return: none
 */

void clean_up(char *line, char *new_line, char **s_arr)
{
	free_arr(s_arr);
	free(line);
	free(new_line);
	free(s_arr);
}
