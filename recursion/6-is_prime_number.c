#include "main.h"
/**
 * _div - check if n is divisible by 2
 * @n: a num
 * @div: divided by
 * Return: 1 if its prime, 0 if its not
 */
int _div(int n, int div)
{
	if (n % div == 0)
		return (0);

	if (div == n / 2)
		return (1);

	return (_div(n, div + 1));
}
/**
 * is_prime_number - check if its prime
 * @n: a num
 * Return: 1 if its prime and 0 if not
 */
int is_prime_number(int n)
{
	int div = 2;

	if (n <= 1)
		return (0);
	if (n >= 2 && n <= 3)
		return (1);

	return (_div(n, div));
}
