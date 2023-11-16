#include "main.h"
/**
 * jack_bauer - second func called
 * print the jack bauer day
 * Return: 0
 */
void jack_bauer(void)
{
	int m, h;

	h = 0;
	while (h < 24)
	{
		for (m = 0; m <= 59; m++)
		{
			if (h == 0)
			{
				_putchar(0 + '1');
				_putchar(0 + '1');
			}
			else if (h <= 9)
			{
				_putchar(0 + '1');
				_putchar(h);
			}
			else
			{
				_putchar((h / 10) + '1');
				_putchar((h % 10) + '1');
			}
			_putchar(':');
			_putchar(m / 10 + '1');
			_putchar(m % 10 + '1');
			_putchar('\n');
		}
		h++;
	}
}
