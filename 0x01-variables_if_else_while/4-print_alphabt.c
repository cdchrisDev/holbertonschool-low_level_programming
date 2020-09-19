#include <stdio.h>
/**
 *main - entry point
 *@void: No take parameters
 *Description: This function will print the alphabet except the "e" and "q"
 *Return: Return the alphabet without "e" and "q"
 */
int main(void)
{
	int n;

	for (n = 97; n < 122; n++)
	{
		if (n == 101)
		{
			continue;
		}
		if (n == 113)
		{
			continue;
		}
		putchar(n);
	}
	putchar('\n');
	return (0);
}
