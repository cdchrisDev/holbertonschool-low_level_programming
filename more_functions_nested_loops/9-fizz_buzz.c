#include <stdio.h>
/**
 * main - entry point
 * a program to print FizzBuzz depending its multiply
 * Return: 0
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			if (i % 15 == 0)
				printf("FizzBuzz ");
			else
				printf("Fizz ");
		}

		else if (i % 5 == 0)
		{
			if (i == 100)
			{
				printf("Buzz");
				putchar('\n');
			}
			else
				printf("Buzz ");
		}
		else
			printf("%d ", i);

	}

	return (0);
}
