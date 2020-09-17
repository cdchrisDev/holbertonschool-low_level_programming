#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *main - entry point
 *@void:No takes parameters
 *Description:  this function will gerate a random number
 *and print its signal
 *Return: "is positive" if its grather than 0
 *	"is negative" if its less than 0
 *	"is zero" if its 0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* code */
	if (n > 0)
	{
		printf("is positive\n");
	}
	else if (n < 0)
	{
		printf("is negative\n");
	}
	else
	{
		printf("is zero\n");
	}
	return (0);
}

