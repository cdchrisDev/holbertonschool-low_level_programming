#include "main.h"
/**
 * more_numbers - print the numbers from 0 to 14 x10
 * Return: 0
 */
void more_numbers(void)
{
	int j, i;

	for (j = 0; j <= 10; j++)
	{
		for (i = 0; i <= 14; i++)
			_putchar(i + '0');


		_putchar('\n');
	}
}
