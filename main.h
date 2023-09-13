#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

char **split_line(char *s);
void my_exec(char **s_arr);

int my_fork(void);
void my_error(char *s);

void print_str_arr(char **s_arr, int arr_len);

#endif /* MAIN_H */
