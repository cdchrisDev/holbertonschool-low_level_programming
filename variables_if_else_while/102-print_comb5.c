#include <stdio.h>
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int i, j;

	while (i != 98 && j != 99)
	{
		for (i = 0; i <= 98; i++)
		{
			for (j = 0; j <= 99; j++)
			{
				if (j < i)
				{
						putchar(i + '0');
						putchar(j + '0');
				}
				else
					continue;
				if (i == 98 && j == 99)
					putchar('\n');
				else
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
		i++;
		j++;
	}
	return (0);
}
