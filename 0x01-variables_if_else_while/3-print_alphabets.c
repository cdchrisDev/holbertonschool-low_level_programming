#include <stdio.h>
/**
 *main - entry point
 *@void: Not takes parameters
 *Description: This function will display the alphabet
 *in capital and minus form
 *Return: nothing but the putchar function
 */

int main(void)
{
	int alph;
	int Alph;

	for (alph = 'a'; alph < 'z'; alph++)
		putchar(alph);
	for (Alph = 'A'; Alph < 'Z'; Alph++)
		putchar(Alph);
	putchar('\n');

	return (0);
}
