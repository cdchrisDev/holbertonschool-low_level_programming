#include "main.h"
/**
 * reverse_array - a func to reverse the content of an array
 * @a: an int
 * @n: a num of elements in the array
 * Return: a reversed array
 */
void reverse_array(int *a, int n)
{
	int i, cap = a[0];

	for (i = 0; i < n; i++)
	{
		n--;
		cap = a[i];
		a[i] = a[n];
		a[n] = cap;
	}
}
