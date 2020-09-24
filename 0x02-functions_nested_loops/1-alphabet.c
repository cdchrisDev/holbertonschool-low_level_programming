#include "holberton.h"
/**
 * print_alphabet - entry point
 * Return: Return the alphabet
 */
void print_alphabet(void)
{
	int Alph;

	for (Alph = 'a'; Alph <= 'z'; Alph++)
	{
		_putchar(Alph);
	}
	_putchar('\n');
}
