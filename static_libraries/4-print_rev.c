#include "main.h"
/**
 * print_rev - print in reverse
 * A simple program to print in reverse
 * @s: character
 * Return: a reversed string
 */
void print_rev(char *s)
{
	int i;

	for (i = 0; *s != '\0'; s++)
		i++;

	s--;

	while (i != 0)
	{
		_putchar(*s);
		i--;
		s--;
	}
	_putchar('\n');
}
