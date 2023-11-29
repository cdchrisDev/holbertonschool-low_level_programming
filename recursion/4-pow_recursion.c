#include "main.h"
/**
 * _pow_recursion - a func to return x raised to the power of y
 * @x: base
 * @y: exponent
 * Return: the result
 */
int _pow_recursion(int x, int y)
{
	int res = x;

	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);

	res *= _pow_recursion(x, y - 1);
	return (res);
}
