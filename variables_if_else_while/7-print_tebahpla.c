#include <stdio.h>
/**
 * main - entry point
 * print the alphabet in reverse
 * @void: no parameter
 * Return: 0
 */
int main(void)
{
	int Alph;

	Alph = 'z';

	while (Alph >= 'a')
	{
		putchar(Alph);
		Alph--;
	}
	putchar('\n');

	return (0);
}
