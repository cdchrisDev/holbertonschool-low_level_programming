#include "main.h"
/**
 * puts_half - a program to cut a string in half
 * a simple program to print a string in half
 * @str: a string
 * Return a halfed string
 */
void puts_half(char *str)
{
	int n, c, len;

	len = 0;

	for (n = 0; *(str + n) != '\0'; n++)
		len++;


	c = len / 2;

	if ((len % 2) == 1)
		c = ((len + 1) / 2);

	for (n = c; str[n] != '\0'; n++)
		_putchar(str[n]);

	_putchar('\n');
}
