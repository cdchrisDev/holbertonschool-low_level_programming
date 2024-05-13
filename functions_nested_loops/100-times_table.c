#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * print_times_table - print the (n) table
 * a function to print the times table of (n) value
 * @n: value
 * Return: void
 */
void print_times_table(int n) 
{
    int j, i, res;

    if (n > 15 || n < 0)
        return;

    for (j = 0; j <= n; j++)
    {
        for (i = 0; i <= n; i++)
        {
            res = j * i;
            if (i == n)
                printf("%d", res);
            else 
            {
                if (((i + 1) * j >= 10) && ((i + 1) * j <= 99))
                    printf("%d,  ", res);
                else if ((i + 1) * j >= 100)
                    printf("%d, ", res);
                else
                    printf("%d,   ", res);
            }
        }
        putchar('\n');
    }
}