#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * op_add - a addtion OP
 * @a: int
 * @b: int
 * Return: op
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - a substraction OP
 * @a: int
 * @b: int
 * Return: OP
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - a multiply op
 * @a: int
 * @b: int
 * Return: OP
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - a divition OP
 * @a: int
 * @b: int
 * Return: OP
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}
/**
 * op_mod - a modulus OP
 * @a: int
 * @b: int
 * Return: OP
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
