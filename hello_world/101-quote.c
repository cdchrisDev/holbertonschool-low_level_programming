#include <stdio.h>
/**
 * main - entry point
 * Return: 1
 */
int main(void)
{
	char *c = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	while (*c)
		putchar(*c++);

	return (1);
}
