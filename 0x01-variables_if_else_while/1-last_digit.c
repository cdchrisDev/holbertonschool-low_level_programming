#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/**
 *main - entry point
 *@void: no takes parameters
 *Description: This function will generate a random number
 *the output will be the las digit of its value and tell if
 *its grather than 5, its 0, or its less than 6 and not 0
 *Return: Will return a value, depending of random number
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	int m = n % 10;
	/* code */
	if (n > 5)
	{
		printf("Last digit of %d is %d and is grather than 5", n, m);
	else if (n < 6 && n != 0)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0", n, m);
	}
	else
	{
		printf("Last digit of %d is %d and is zero", n, m);
	}
	return (0);
}

