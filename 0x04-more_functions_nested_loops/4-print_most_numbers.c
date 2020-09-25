#include "holberton.h"
/**
 *print_most_numbers - entry point
 *@void: no takes argumenst
 *Description: print the numbers from 0 to 9, except the 2 and 4
 *Return: no returned
 */
void print_most_numbers(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		if (n == 2)
		{
			continue;
		}
		if (n == 4)
		{
			continue;
		}
		_putchar(n + '0');
	}
	_putchar('\n');
}
