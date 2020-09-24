#include "holberton.h"
/**
 *print_alphabet_x10 - entry point
 *@void: takes no arguments
 *Description: increment letter a until reach z by 10 times
 *Return: print the alphabet x10
 */

void print_alphabet_x10(void)
{
	int Alph;
	int i;

	for (i = 1; i <= 10; i++)
	{
		for (Alph = 'a'; Alph <= 'z'; Alph++)
		{
			_putchar(Alph);
		}
	_putchar('\n');
	}
}

