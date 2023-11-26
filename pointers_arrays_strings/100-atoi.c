#include "main.h"
/**
 * _atoi -a func to convert a string to int
 * @s: a char
 * Return: 0
 */
int _atoi(char *s)
{
int sign = 1;
	unsigned int num = 0;

	do {
		if (*s == '-')
			sign *= -1;

		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');

		else if (num > 0)
			break;

	} while (*s++);

	return (num * sign);
/*	int sign;
	unsigned int val;

	val = 0;
	sign = 1;

	while (*s++ != '\0')
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
			val = (val * 10) + (*s - '0');

		else if (val > 0)
			break;
	}
	return (sign * val);
*/	
}
