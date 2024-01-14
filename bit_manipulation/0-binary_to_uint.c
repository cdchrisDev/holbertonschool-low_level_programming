#include "main.h"
/**
 * binary_to_uint - a func to convert from binary to uint
 * @b: string of 0 or 1 char
 * Return: uint
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;
	int base = 1, i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i + 1] != '\0'; i++)
		if (b[i] != '0' && b[i] != '1')
			return (0);

	while (i >= 0)
	{
		res += ((b[i] - '0') * base);
		base *= 2;
		i--;
	}
	return (res);
}
