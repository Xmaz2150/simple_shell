#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h>

#define TOKKEN_DELIMS " \t\0"

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

int my_exec(char **s_arr, char **p_arr, char **argv, char *line, char *new_line, int l_count);
void my_prompt(char *str);

my_list *create_list(char *str);
char *get_path(const char *p_name, char **p_arr);
my_list *path_list(char *str, my_list *list);
char *get_cmd_path(char *command, char **p_arr);

void my_error(char **argv, char **s_arr, int cmdcount_int, char *str, char *new_str);

int _atoi(char *s);
int tens_multiplier(int pos, char *s);
int print_str_arr(char **s_arr);
char *int_to_str(int n);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

int my_built_in(char **s_arr, char **p_arr, char *str, char *new_str, int cdnum);
int my_exit(char **s_arr, char *str, char *new_str, int l_count);
int my_cd(char **s_arr, char **p_arr);

char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *str_concat_helper(char *new_str, char *s1, char *s2);
char **split_line(char *s);

void ctrl_c(int signum);
int ctrl_d(char *str);

void clean_up(char *str, char *new_str, char **s_arr);
void free_arr(char **s_arr);
char *str_realloc(char *str);
void free_list(my_list *head);

#endif /* MAIN_H */
