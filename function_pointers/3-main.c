#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * main - entry point
 * @argc: name of program
 * @argv: arguments for OP
 * Return: op
 */
int main(int argc, char *argv[])
{
	char *op;
	int n1, n2;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);
	op = argv[2];

	if (op == NULL)
	{
		printf("Error\n");

		exit(98);
	}

	printf("%d\n", get_op_func(op)(n1, n2));
	return (0);
}