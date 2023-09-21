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
	my_list *ptr, *head;
	char *dir;
	int i = 0, j = 0, stcnt = 0, dir_len = 0;

	if (path ==  NULL)
		return (NULL);
	head = create_list(path);
	ptr = head;
	while (ptr != NULL)
	{
		if (path[i] == ':' || path[i] == '\0')
		{
			if (path[i] != '\0')
				i++;
			dir = malloc(sizeof(char) * dir_len + 2);
			if (dir == NULL)
				return (NULL);
			while (path[stcnt] != ':' && path[stcnt] != '\0')
			{
				dir[j] = path[stcnt];
				stcnt++;
				j++;
			}
			dir[j++] = '/';
			dir[j] = '\0';
			stcnt = i;
			j = 0;
			ptr->dir = dir;
			ptr = ptr->next;
		}

		else
		{
			dir_len++;
			i++;
		}
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

char *get_cmd_path(char **p_arr, char *command)
{
	char *path, *full_path;
	struct stat buffer;
	my_list *tmp, *paths;

	path = my_path(p_arr);
	if (path == NULL)
	{
		write(STDERR_FILENO, "PATH not found", 16);
		_exit(0);
	}
	paths = path_list(path);
	if (paths == NULL)
	{
		write(STDERR_FILENO, "PATH List err", 13);
		_exit(0);
	}

	tmp = paths;
	while (tmp != NULL)
	{
		if (path[0] == ':')
			full_path = str_concat("./", command);
		else
			full_path = str_concat(tmp->dir, command);
		if (full_path == NULL)
			return (NULL);
		if (stat(full_path, &buffer) == 0 && access(full_path, X_OK) == 0)
		{
			free_list(paths);
			return (full_path);
		}
		tmp = tmp->next;
		free(full_path);
	}
	return (NULL);
}
