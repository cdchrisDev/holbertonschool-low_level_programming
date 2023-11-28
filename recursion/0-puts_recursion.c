#include <stdlib.h>
#include "main.h"
/**
 * _puts_recursion - a func to print a string, followed newline
 * @s: a char
 * Return: 0
 */
void _puts_recursion(char *s)
{
	_putchar(*s);
	s++;
	if (*s != '\0')
		_puts_recursion(s);
	else if (*s == '\0')
		_putchar('\n');
	else
		_putchar('\0');
}
