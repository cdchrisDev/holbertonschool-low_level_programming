#include "variadic_functions.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * sum_them_all - sum all the args
 * @n: a num
 * Return: the sum of all
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list MoArg;
	unsigned int i, add = 0;
	/* set the start of infinite arg list */
	va_start(MoArg, n);
	for (i = 0; i < n; i++)
	{
		if (n == 0)
			return (0);

		add += va_arg(MoArg, int);
	}
	va_end(MoArg);
	return (add);
}
