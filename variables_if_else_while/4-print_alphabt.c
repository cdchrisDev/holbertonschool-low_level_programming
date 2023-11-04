#include <stdio.h>
/**
 * main - entry point
 * Alphabet that skip the 'q' and 'e'
 * @void: no parameter
 * Return: 0
 */
int main(void)
{
	int Alph;

	for (Alph = 'a';Alph != 'z' + 1; Alph++)
	{	
		if (Alph == 'q' || Alph == 'e')
			continue;

		putchar(Alph);
	}

	return(0);
}
