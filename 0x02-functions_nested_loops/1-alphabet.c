#include "holberton.h"
/**
 * void print_alphabet(void) - entry point 
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
