#include "main.h"
/**
 * flip_bits - a func that returs a numbers you need to flip
 * @n: integer
 * @m: integer
 * Return: int
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int t;
	int i = 0;

	t = n ^ m;
	while (t >= 1)
	{
		if ((t & 1) == 1)
		i++;
		t >>= 1;
	}
	return (i);
}
