#include <stdlib.h>
#include <stdio.h>
/**
 * main - program that prints its name, followed by a new line.
 * @argc: counter of args
 * @argv: args array
 * Return: 1
 */
int main(int argc, char **argv)
{
	printf("%s\n", argv[0]);
	(void)argc;
	return (0);
}
