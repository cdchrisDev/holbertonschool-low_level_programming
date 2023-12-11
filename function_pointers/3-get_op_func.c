#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * get_op_func - a func to select the correct OP
 * @s: string
 * Return: OP
 */


int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{"+", op_add},
	{"-", op_sub},
	{"*", op_mul},
	{"/", op_div},
	{"%", op_mod},
	{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL)
	{
		if (*ops[i].op == *s && s[1] == '\0')
			return (ops[i].f);

		i++;
	}
	printf("Error\n");
	exit(99);
}
