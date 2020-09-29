#include "holberton.h"
/**
 *swap_int - entry point
 *@a: the swap number
 *@b: the swap number
 *Description: this function swap the values of the variables
 *return: it returned in void
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;

	*a = *b;
	*b = temp;
}
