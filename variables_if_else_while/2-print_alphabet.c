#include <stdio.h>
/**
 * main - entry point
 * a program to print alphabet
 * @void: no parameters
 * Return: 0
 */
int main(void){
	int Alph;

	Alph = 'a';

	while (Alph <= 'z')
	{
		putchar(Alph);
		Alph++;
	}
	putchar('\n');

	return (0);
}	
