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

	n = '0';

	while (n < '9' + 1)
	{
		putchar(n);
		n++;
	}
	putchar('\n');

	return (0);
}
