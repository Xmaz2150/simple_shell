#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * struct node - linked list structure for PATH variable
 * @dir: Input, directory
 * @next: Input, pointer to next node
 */

typedef struct node
{
	char *dir;
	struct node *next;
}
my_list;

char **split_line(char *s);
int my_exec(char **s_arr, char **p_arr, char **argv, char *str, char *new_str, int l_count);

void clean_up(char **s_arr, char *str, char *new_str);
void my_error(char **s_arr, char **argv, char *str, char *new_str, int l_count);
void my_prompt(char *str);
int my_built_in(char **s_arr, char **p_arr, char *str, char *new_str, int l_count);

void free_arr(char **addr);
void print_str_arr(char **s_arr);
int line_check(char *s);
char *int_to_str(int n);
void free_list(my_list *head);
char *str_realloc(char *str);
int _strlen(char *s);
int _atoi(char *s);
int tens_multiplier(int pos, char *s);
char *_strdup(char *str);
char *str_concat_helper(char *new_str, char *s1, char *s2);

int my_exit(char **s_arr, char *str, char *new_str, int l_count);
char *my_path(char **p_arr);
my_list *create_list(char *str);
my_list *path_list(char *path);

char *str_concat(char *s1, char *s2);
char *get_cmd_path(char **p_arr, char *command);

void ctrl_c(int signum);
int ctrl_d(char *str);

void my_execve_child(int pipe_fd[2], char *command, char **s_arr);
void my_execve_parent(int pipe_fd[2]);

#endif /* MAIN_H */
