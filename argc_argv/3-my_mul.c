#include <stdio.h>
#include <stdlib.h>
/**
 * main - a func to mul two numbers
 * @argc: counter of int on argv
 * @argv: arguments
 * Return: The result and \n, if is not 2 arg, print: error, return 1
 */
int main (int argc, char **argv)
{
	(void)argc;
	if (*argv > 3)
	{
		printf("Error");
		return (1);
	}
	else
	{
		printf("%d\n", argv[1 - '0'] *= argv[2 - '0']);
	}
	return (EXIT_SUCCESS);
}
