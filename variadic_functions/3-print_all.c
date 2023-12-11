#include "variadic_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
/**
 * print_all - a func that prints anything
 * @format: struct of format
 * Return: anything
 */
void print_all(const char * const format, ...)
{
	int i, cnt = 0;
	char c;
	float f;
	char *s;
	va_list MoArg;

	va_start(MoArg, format);
	while (format && format[cnt] != '\0')
	{
		switch (format[cnt])
		{
			case 'c':
				c = va_arg(MoArg, int);
				printf("%c", c);
				break;
			case 'i':
				i = va_arg(MoArg, int);
				printf("%d", i);
				break;
			case 'f':
				f = va_arg(MoArg, double);
				printf("%f", f);
				break;
			case 's':
				s = va_arg(MoArg, char*);
				if (s == NULL)
					printf("(nil)");
				else
					printf("%s", s);
				break;
			default:
				cnt++;
				continue;
		}
		if (format[cnt + 1])
			printf(", ");
		cnt++;
	}
	va_end(MoArg);
	putchar('\n');
}
