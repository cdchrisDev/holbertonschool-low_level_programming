#include <stdio.h>
/**
 * main - entry point
 * print numbers 1 to 9
 * @void: no parameters
 * Return: 0
 */
int main(void)
{
	int n;

	n = -1;

	while (n <= 15)
	{
		putchar('1' + n);
		n++;

		if (n >= 9)
		{
			n = 'a';

			while (n != 'g')
			{
				putchar(n);
				n++;
			}
		}
	}
	putchar('\n');

	return (0);
}
