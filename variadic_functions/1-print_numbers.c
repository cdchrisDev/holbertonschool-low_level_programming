#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_numbers - func to print nums
 * @separator: string
 * @n: num of arg
 * Return: printed nums
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list MoArg;
	unsigned int i;

	va_start(MoArg, n);

	for (i = 0; i < n; i++)
	{
		if (1 + i == n)
			printf("%d", va_arg(MoArg, int));
		else if (separator == NULL)
			printf("%d", va_arg(MoArg, int));
		else
			printf("%d%s", va_arg(MoArg, int), separator);
	}
	putchar('\n');
}
