#include "main.h"
/**
 * swap_int - swaper for 2 ints
 * this program swap the position of 2 var
 * @a: num to swap
 * @b: num to swap
 * Return: the swapped nums
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
