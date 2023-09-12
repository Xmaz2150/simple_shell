#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char **split_line(char *s);
void my_exec(char **s_arr);

/**
 * my helpers
 */

int my_fork(void);
void my_error(char *s);

#endif /* MAIN_H */
