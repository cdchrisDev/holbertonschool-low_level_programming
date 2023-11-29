#include <stdio.h>
#include <stdlib.h>
/**
 * main - print arguments
 * @argc: int of argv
 * @argv: arguments
 * Return: 1
 */
int main(int argc, char **argv)
{
	int i = 0;

	while (i != argc)
	{
		printf("%s\n", *(argv + i));
		i++;
	}
	return (EXIT_SUCCESS);
}
