#include "main.h"

/**
 * my_error - error handling
 * @argv: Input, arg vector
 * @s_arr: Input, tokken arr
 * @line: Input, input
 * @new_line: Input, input realloced
 * @l_cnt: Input, shell iterations
 *
 * Return: none
 */

void my_error(char **argv, char **s_arr, int l_cnt, char *line,
		   char *new_line)
{
	char *num;

	num = int_to_str(l_cnt);
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num, _strlen(num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, s_arr[0], _strlen(s_arr[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
	free(num);
	clean_up(line, new_line, s_arr);
	exit(0);
}
