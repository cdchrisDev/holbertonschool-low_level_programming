#include <stdio.h>
#include <stdlib.h>
/**
 * main - a func to mul two numbers
 * @argc: counter of int on argv
 * @argv: arguments
 * Return: The result and \n, if is not 2 arg, print: error, return 1
 */
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int res, den, mul;

		den = atoi(argv[1]);
		mul = atoi(argv[2]);
		res = den * mul;
		printf("%d\n", res);
		return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (EXIT_SUCCESS);
}
