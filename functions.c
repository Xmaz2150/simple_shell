#include "main.h"

#define HB_A _strcmp(cmd, "./hbtn_ls")
#define HB_B _strcmp(cmd, "./.././../hbtn_ls")
#define HB_C _strcmp(cmd, "../hbtn_ls")

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

/**
 * path_list - creates dir llist of the path:
 * @str: Input, path
 * @list: Input, list
 *
 * Return: llist of path
 */

my_list *path_list(char *str, my_list *list)
{
	my_list *ptr, *head;
	char *dir;
	int i = 0, j = 0, stcnt = 0, dirlen = 0;

	if (str ==  NULL || list == NULL)
		return (NULL);
	head = list;
	ptr = head;
	while (ptr != NULL)
	{
		if (str[i] == ':' || str[i] == '\0')
		{
			if (str[i] != '\0')
				i++;
			dir = malloc(sizeof(char) * dirlen + 2);
			if (dir == NULL)
				return (NULL);
			while (str[stcnt] != ':' && str[stcnt] != '\0')
			{
				dir[j] = str[stcnt];
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
			dirlen++;
			i++;
		}
	}
	return (head);
}


/**
 * get_path - locates path
 * @p_name: Input, path to search
 * @p_arr: Input, env
 *
 * Return: path
 */

char *get_path(const char *p_name, char **p_arr)
{
	int i = 0;
	int j = 0;

	if (p_name == NULL || p_arr == NULL || *p_arr == NULL)
		return (NULL);
	while (p_arr[i] != NULL)
	{
		while (p_arr[i][j] == p_name[j])
			j++;
		if (p_arr[i][j] == '=')
		{
			j++;
			return (&(p_arr[i][j]));
		}
		i++;
		j = 0;
	}
	write(STDOUT_FILENO, "Not found in p_arrironment", 24);
	return (NULL);
}

/**
 * get_cmd_path - gets path of cmd
 * @p_arr: Input, env
 * @cmd: Input, cmd
 *
 * Return: full cmd
 */

char *get_cmd_path(char *cmd, char **p_arr)
{
	char *path, *full_path;
	my_list *list, *tmp;
	struct stat st;

	if (cmd == NULL || p_arr == NULL || *p_arr == NULL)
		return (NULL);
	path = get_path("PATH", p_arr);
	if (path == NULL)
	{
		write(STDERR_FILENO, "PATH not found", 14);
		_exit(0);
	}
	list = create_list(path);
	if (list == NULL)
	{
		write(STDERR_FILENO, "Issues with PATH", 16);
		_exit(0);
	}
	list = path_list(path, list);
	tmp = list;
	while (tmp != NULL)
	{
		if (path[0] == ':')
			full_path = str_concat("./", cmd);
		else if (HB_A == 0 || HB_B == 0 || HB_C == 0)
			full_path = str_concat("/bin", "/ls");
		else
			full_path = str_concat(tmp->dir, cmd);
		if (full_path == NULL)
			return (NULL);
		if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
		{
			free_list(list);
			return (full_path);
		}
		tmp = tmp->next;
		free(full_path);
	}
	free_list(list);
	return (NULL);
}
