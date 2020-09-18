#include <stdio.h>
/**
 *main - entry point
 *@void: No takes parameters
 *Description: This function display the alphabet
 *Return: 0 = nothing but the putchar() function
 */

int main(void)
{
	int Alph;

	for (Alph = 'a'; Alph <= 'z'; Alph++)
		putchar(Alph);
	putchar('\n');

	return (0);
}

