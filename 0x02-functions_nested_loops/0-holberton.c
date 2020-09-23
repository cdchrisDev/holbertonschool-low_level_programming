#include "holberton.h"
/**
 *main - entry point
 *@void: takes no arguments
 *Return: 0 = nothing but the _putchar() function
 */

int main(void)
{
	int _putchar(char c);

	char Hol[] = "Holberton";
	int letter;

	for (letter = 0; letter <= 8; letter++)
	{
		_putchar(Hol[letter]);
	}
	_putchar('\n');
	return (0);
}
