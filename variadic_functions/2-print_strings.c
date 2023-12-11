#include <stdarg.h>
#include "variadic_functions.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_strings - a func to print strings
 * @separator: a string
 * @n: num of args
 * Return: a string
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
		unsigned int i;
		va_list MoArg;

		va_start(MoArg, n);

		for (i = 0; i < n; i++)
		{	/* Convert to char from Int*/
			char *c = va_arg(MoArg, char *);

			if (1 + i == n || separator == NULL)
				printf("%s", c);
			else if (c != NULL)
				printf("%s%s", c, separator);

			if (c == NULL)
				printf("(nil)");
		}
		va_end(MoArg);
		putchar('\n');
}
