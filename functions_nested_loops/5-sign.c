#include "main.h"
/**
 * print_sign - 2th func called
 * a func to check if its positive and negative and just print the sign
 * @n: a number
 * Return: a sign
 */
int print_sign(int n)
{
	int pos, neg;

	pos = 43;
	neg = 45;

	if (n > 0)
	{
		_putchar(pos);
		return (1);
	}
	else if (n < 0)
	{
		_putchar(neg);
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
