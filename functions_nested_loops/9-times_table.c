#include "main.h"
/**
 * times_table - a function to print 9th table
 * @void: no parameters
 * Return: no return
 */

void times_table(void)
{
	int den, mul, result;

	for (den = 0; den < 10; den++)
	{

		for (mul = 0; mul < 10; mul++)
		{
			result = den * mul;
			/* result */
			if (result >= 0 && result <= 9)
				_putchar(result + '0');
			else
			{
				_putchar(result / 10 + '0');
				_putchar(result % 10 + '0');
			}
			/* identation */
			if (result + den >= 10 && mul != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
			else if (result + den <= 10 && mul != 9)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
