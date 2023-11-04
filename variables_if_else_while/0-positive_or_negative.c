#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - entry point
 * A program to tell if random NUM is equal or different to 0
 * @void: no parameter
 * Return: 0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
	{
		printf("%d is positive\n", n);
		if (n < 0)
			printf("%d is negative\n", n);
	}
	else
		printf("%d is zero\n", 0);

	return (0);
}
