#include "main.h"
/**
 * factorial - a func that return factorial of a num
 * @n: a num
 * Return: -1 if is lower (error) - fact' of 0 is 1
 */
int factorial(int n)
{
	if (n == 0)
		return (1);
	else if (n < 0)
		return (-1);
	else
		return (n * factorial(n - 1));
}
