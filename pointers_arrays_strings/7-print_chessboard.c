#include "main.h"
/**
 * print_chessboard - a func to print the chessboard
 * @a: a chess piece
 * Return: the cheesboard
 */
void print_chessboard(char (*a)[8])
{
	int i = 0;

	for (; i < 8; i++)
	{
		int j = 0;

		for (; j < 8; j++)
		{
			_putchar(a[i][j]);
		}
		_putchar('\n');
	}
}
