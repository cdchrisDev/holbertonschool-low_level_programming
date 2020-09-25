#include "holberton.h"
/**
 *more_numbers - entry point
 *@void: no takes arguments
 *Description: this function print 10 times the numbers from 0 to 14
 *Return: no returned
 */
void more_numbers(void)
{
	int Ncounter;
	int nums;

	for (Ncounter = 1; Ncounter <= 10; Ncounter++)
	{
		for (nums = 0; nums <= 14; nums++)
		{
			if (nums >= 10 && nums <= 14)
			{
				_putchar(nums / 10 + '0');
			}
			_putchar(nums % 10 + '0');
		}
		_putchar('\n');
	}
}
