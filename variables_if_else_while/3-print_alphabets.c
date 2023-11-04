#include <stdio.h>
/**
 * main - entry point
 * a program that print Alphbt on minus and cap
 * @void: no parameter
 * Return: 0
 **/
int main(void)
{
	int Alph;

	Alph = 'a';

	while (Alph >='a' || Alph <= 'Z')
	{
		putchar(Alph);
		Alph++;

		if (Alph > 'z')
			Alph = 'A';
	}
	return (0);
}
