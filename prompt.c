#include "main.h"

/**
 * my_prompt - prints prompt to stdout
 * @str: Input, prompt
 *  Return: none
 */

void my_prompt(char *str)
{
	write(STDOUT_FILENO, str, 2);
}
