#include "main.h"
/**
 * set_bit - func that sets the value of a bit to 1
 * @n: integer
 * @index: the index
 * Return: 1 or 0 if fail
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i = 1;

	if (sizeof(n) * 8 < index)
		return (-1);

	i <<= index;
	*n |= i;
	return (1);
}
