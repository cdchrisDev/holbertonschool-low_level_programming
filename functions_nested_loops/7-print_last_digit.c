#include "main.h"
/**
 * print_last_digit - 2th func called
 * a func to print the last digit of a number
 * @n: a int
 * Return: the value of the last digit
 */

int print_last_digit(int n)
{
	int j;

	if (n < 0)
	{
		j = (n % 10) * -1;

		_putchar(j + '0');
		return (j);
	}
	else
	{
		j = n % 10;

		_putchar(j + '0');
		return (j);
	}
}
