#include "main.h"
/**
 * get_bit - a func to return value of a bit on index
 * @n: integer
 * @index: the index
 * Return: integer
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (sizeof(n) * 8 < index)
		return (-1);

	n >>= index;
	if ((n & 1) == 1)
		return (1);
	else
		return (0);
}
