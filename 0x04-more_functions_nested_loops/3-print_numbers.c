#include "holberton.h"
/**
 *print_numbers - entry point
 *@void: takes no parameters
 *Description: this function print numbers from 0 to 9
 *Return: 0
 */
void print_numbers(void)
{
	int nums;
		
	for (nums = 0; nums <= 9; nums++)
	{
		_putchar(nums + '0');
	}
	_putchar('\n');
}

