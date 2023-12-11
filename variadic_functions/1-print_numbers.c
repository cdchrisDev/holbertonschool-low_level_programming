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
		printf("%d", va_arg(MoArg, int));
		if (separator == NULL)
			return;
		else if (i + 1 == n)
			putchar(va_arg(MoArg, int));
		else
		{
			putchar(*separator);
			putchar(' ');
		}
	}
	putchar('\n');
}
