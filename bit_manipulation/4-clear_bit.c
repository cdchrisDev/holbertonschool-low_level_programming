#include "main.h"
/**
 * clear_bit - a func that sets bit to 0
 * @n: integer
 * @index: the index
 * Return: 1 or 0 if it fails
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i = 1;

	if (sizeof(n) * 8 < index)
		return (-1);

	i <<= index;
	*n &= ~i;
	return (1);
}
