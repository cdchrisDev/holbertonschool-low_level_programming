#include <stdlib.h>
#include <stdio.h>
/**
 * main - func to return int of argv
 * @argc: counter to int
 * @argv: array of arguments
 * Return: 1
 */
int main(int argc, char **argv)
{
	printf("%d\n", argc);
	(void)**argv;
	return (EXIT_SUCCESS);
}
