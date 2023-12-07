#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_name - a func that prints a name
 * @name: a name
 * @f: func pointer to a name
 * Return: a name
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL)
		return;

	(*f)(name);
}
