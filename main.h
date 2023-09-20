#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct node
{
	char *dir;
	struct node *next;
}
my_list;

char **split_line(char *s);
void my_exec(char **s_arr, char **p_arr);

int my_fork(void);
void my_error(char *s);
void my_prompt(char *str);
int my_built_in(char **s_arr, char **p_arr);

void free_arr(char ***addr);
void print_str_arr(char **s_arr);
int line_check(char *s);

char *my_path(char **p_arr);
my_list *path_list(char *path);

char *str_concat(char *s1, char *s2);
char *get_cmd_path(my_list *path_list, char *command);

void ctrl_c(int signum);

#endif /* MAIN_H */
