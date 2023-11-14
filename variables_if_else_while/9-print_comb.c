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

	n = 48;

	while (n <= 57)
	{
		if (n == 57)
		{
			putchar(n);
			break;
		}
		else
		{
			putchar(n);
			putchar(',');
			putchar(' ');
		}
		n++;
	}
	return (0);
}
