#include <stdio.h>
/**
 * main - entry point
 * print num ascending order
 * @void: no parameters
 * Return: 0
 */
int main(void)
{
	int n;

	n = -1;

	while (n <= 7)
	{
		if (n == 9)
		{
			continue;
		}

		putchar(n + '1');
		n++;
		putchar(',');
		putchar(' ');
	}

	putchar('9');

	return (0);
}
