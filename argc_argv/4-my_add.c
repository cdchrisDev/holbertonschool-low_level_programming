#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - a func to add positive nums
 * @argc: counter of int for argv
 * @argv: char string
 * Return: 1
 */
int main(int argc, char **argv)
{
	int res;
	unsigned int i = 0;
	char *c;

	if (argc == 1)
		printf("0\n");

	if (argc > 1)
	{
		while (*argv[i++] != '\0')
		{
			c = argv[i];

			if (*argv[i] < 48 || *argv[i] > 57)
			{
				printf("Error\n");
				return (1);
			}
			else
			{
				res += atoi(c);
			}
		}
		printf("%d\n", res);
	}
	return (0);
}
