#include "main.h"
/**
 * jack_bauer - second func called
 * print the jack bauer day
 * Return: 0
 */
void jack_bauer(void)
{
	int i;



	for (i = 0; i < 1440; i++)
	{
		_putchar(i / 60 / 10 + '0');
		_putchar(i / 60 % 10 + '0');
		_putchar(':');
		_putchar(i % 60 / 10 + '0');
		_putchar(i % 60 % 10 + '0');
	_putchar('\n');
	}
}
