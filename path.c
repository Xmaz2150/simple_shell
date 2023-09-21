#include "main.h"

/**
 * my_path - locates path
 * @p_arr: Input, env
 *
 * Return: path
 */

char *my_path(char **p_arr)
{
	int i, j;
	char *path, *s;

	s = "PATH";
	for (i = 0; p_arr[i] != NULL; i++)
	{
		for (j = 0; p_arr[i][j] != '\0'; j++)
		{
			if (p_arr[i][j] == s[j])
				path = p_arr[i] + 5;
		}
	}
	return (path);
}

/**
 * path_list - creates dir llist of the path:
 * @path: Input, path
 *
 * Return: llist of path
 */

my_list *path_list(char *path)
{
	my_list *head = NULL;
	my_list  *tail = NULL;
	char *dir;

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		my_list *new_node;

		new_node = (my_list *)malloc(sizeof(my_list));
		new_node->dir = strdup(dir);
		new_node->next = NULL;

		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
		dir = strtok(NULL, ":");
	}
	return (head);
}

/**
 * get_cmd_path - gets path of command
 * @path_list: Input, path
 * @command: Input, command
 *
 * Return: full command
 */

char *get_cmd_path(my_list *path_list, char *command)
{
	char *full_path;
	int command_len, dir_len;
	struct stat buffer;
	my_list *tmp;

	if (path_list != NULL)
	{
		command_len = _strlen(command);

		tmp = path_list;
		while (tmp != NULL)
		{
			dir_len = strlen(tmp->dir);
			full_path = malloc(command_len + dir_len + 2);
			strcpy(full_path, tmp->dir);
			strcat(full_path, "/");
			strcat(full_path, command);
			strcat(full_path, "\0");
			if (stat(full_path, &buffer) == 0)
			{
				return (full_path);
			}

			tmp = tmp->next;
		}
		return (NULL);
	}
	return (NULL);
}
