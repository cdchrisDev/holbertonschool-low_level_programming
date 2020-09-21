#include "holberton.h"
/**
 *main - entry point
 *@void: No takes parameters
 *Description: This function display the alphabet
 *Return: 0 = nothing but the putchar() function
 */

int main(void)
{

char Alph;

	for (Alph = 'a'; Alph <= 'z'; Alph++)
	{
		_putchar(Alph);
	}
		_putchar('\n');
	return (0);
}

