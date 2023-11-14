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

	n = 0;

	while (n <= 9)
	{
		putchar((n % 10) + '0');
		if (n == 9)
			break;

		n++;

		putchar(',');
		putchar(' ');	
	}
	putchar('\n');
	return (0);
}
