#include <stdio.h>
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int i, j, o;

	o = 0;

	while (o <= 7)
	{
		for (i = 0; i <= 8; i++)
		{
			for (j = 0; j <= 9; j++)
			{
				if ((j > i) && (i > o))
				{
					putchar(o + '0');
					putchar(i + '0');
					putchar(j + '0');
				}
				else
					continue;

				if (i == 8 && j == 9 && o == 7)
					putchar('\n');
				else
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
		o++;
	}
	return (0);
}
