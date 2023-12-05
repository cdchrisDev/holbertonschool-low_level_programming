#include "main.h"
#include <stdlib.h>
/**
 * print_chessboard - a func to print a chessboard
 * @a[8]: a char
 * Return: print a chessboard
 */
void print_chessboard(char (*a)[8])
{
	int i = 0, j = 0;

	for (; *a[i] != '\0'; i++)
	{
		for (; *a[j] != '\0'; j++)
		{
			if (j == '\0')
				_putchar('\n');
			else
				_putchar(a);
		}
		j = 0;
	}
}
