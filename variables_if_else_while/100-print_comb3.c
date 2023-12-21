#include <stdio.h>
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int i, j;

	for (i = 0; i <= 8; i++)
	{

		for (j = 0; j <= 9; j++)
		{
			if (j > i)
			{
				putchar(i + '0');
				putchar(j + '0');
			}
			else
				continue;

			if (i == 8 && j == 9)
				putchar('\n');
			else
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	return (0);
}
