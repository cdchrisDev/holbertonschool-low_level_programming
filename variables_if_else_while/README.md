# C - Variables, if, else, while
### Resources
* [Keywords and identifiers](https://publications.gbdirect.co.uk//c_book/chapter2/keywords_and_identifiers.html)
* [integers](https://publications.gbdirect.co.uk//c_book/chapter2/integral_types.html)
* [Arithmetic Operators in C](https://www.tutorialspoint.com/cprogramming/c_arithmetic_operators.htm)
* [If statements in C](https://www.cprogramming.com/tutorial/c/lesson2.html)
* [if…else statement](https://www.tutorialspoint.com/cprogramming/if_else_statement_in_c.htm)
* [Relational operators](https://www.tutorialspoint.com/cprogramming/c_relational_operators.htm)
* [Logical operators](https://www.fresh2refresh.com/c-programming/c-operators-expressions/c-logical-operators/)
* [while loop in C](https://www.tutorialspoint.com/cprogramming/c_while_loop.htm)
* [While loop](https://www.youtube.com/watch?v=Ju1LYO9pkaI&ab_channel=TheBadTutorials)
## 0. This program will assign a random number to the variable n each time it is executed. Complete the source code in order to print whether the number stored in the variable n is positive or negative.<br />

* You can find the source code here
* The variable n will store a different value every time you will run this program
* You don’t have to understand what rand, srand, RAND_MAX do. Please do not touch this code
* The output of the program should be:
	* The number, followed by
	* if the number is greater than 0: is positive
	* if the number is 0: is zero
	* if the number is less than 0: is negative
	* followed by a new line
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-positive_or_negative.c -o 0-positive_or_negative
julien@ubuntu:~/$ ./0-positive_or_negative 
-520693284 is negative
julien@ubuntu:~/$ ./0-positive_or_negative 
-973398895 is negative
julien@ubuntu:~/$ ./0-positive_or_negative 
-199220452 is negative
julien@ubuntu:~/$ ./0-positive_or_negative 
561319348 is positive
julien@ubuntu:~/$ ./0-positive_or_negative 
561319348 is positive
julien@ubuntu:~/$ ./0-positive_or_negative 
266853958 is positive
julien@ubuntu:~/$ ./0-positive_or_negative 
-48147767 is negative
julien@ubuntu:~/$ ./0-positive_or_negative 
0 is zero
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - entry point
 * A program to tell if random NUM is equal or different to 0
 * @void: no parameter
 * Return: 0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
		printf("%d is positive\n", n);
	else if (n < 0)
		printf("%d is negative\n", n);
	else
		printf("%d is zero\n", 0);

	return (0);
}
```
## 1. This program will assign a random number to the variable n each time it is executed. Complete the source code in order to print the last digit of the number stored in the variable `n`.<br />

* You can find the source code here
* The variable n will store a different value every time you run this program
* You don’t have to understand what rand, srand, and RAND_MAX do. Please do not touch this code
* The output of the program should be:
	* The string Last digit of, followed by
	* n, followed by
	* the string is, followed by
		- if the last digit of n is greater than 5: the string and is greater than 5
		- if the last digit of n is 0: the string and is 0
		- if the last digit of n is less than 6 and not 0: the string and is less than 6 and not 0
	* followed by a new line
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-last_digit.c -o 1-last_digit
julien@ubuntu:~/$ ./1-last_digit 
Last digit of 629438752 is 2 and is less than 6 and not 0
julien@ubuntu:~/$ ./1-last_digit 
Last digit of -748255693 is -3 and is less than 6 and not 0
julien@ubuntu:~/$ ./1-last_digit 
Last digit of -1052791662 is -2 and is less than 6 and not 0
julien@ubuntu:~/$ ./1-last_digit 
Last digit of -284805734 is -4 and is less than 6 and not 0
julien@ubuntu:~/$ ./1-last_digit 
Last digit of -284805734 is -4 and is less than 6 and not 0
julien@ubuntu:~/$ ./1-last_digit 
Last digit of 491506926 is 6 and is greater than 5
julien@ubuntu:~/$ ./1-last_digit 
Last digit of 954249937 is 7 and is greater than 5
julien@ubuntu:~/$ ./1-last_digit 
Last digit of 652334952 is 2 and is less than 6 and not 0
julien@ubuntu:~/$ ./1-last_digit 
Last digit of -729688197 is -7 and is less than 6 and not 0
julien@ubuntu:~/$ ./1-last_digit 
Last digit of -729688197 is -7 and is less than 6 and not 0
julien@ubuntu:~/$ ./1-last_digit 
Last digit of 45528266 is 6 and is greater than 5
julien@ubuntu:~/$ ./1-last_digit 
Last digit of 45528266 is 6 and is greater than 5
julien@ubuntu:~/$ ./1-last_digit 
Last digit of 809065140 is 0 and is 0
julien@ubuntu:~/$
```
**SOLVED**
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - entry point
 * assing a random Num to
 * @void: no parameter
 * Return: 0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n % 10 == 0)
	{
		printf("Last digit of %d is %d and is 0\n", n, n % 10);
	}
	else if (n % 10 < 5)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, n % 10);
	}
	else
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, n % 10);
	}
	return (0);
}
```
## 2. Write a program that prints the alphabet in lowercase, followed by a new line.<br />

* You can only use the `putchar` function (every other function (`printf`, `puts`, etc…) is forbidden)
* All your code should be in the `main` function
* You can only use `putchar` twice in your code
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-print_alphabet.c -o 2-print_alphabet
julien@ubuntu:~/$ ./2-print_alphabet 
abcdefghijklmnopqrstuvwxyz
julien@ubuntu:~/$
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * a program to print alphabet
 * @void: no parameters
 * Return: 0
 */
int main(void)
{
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
```
## 3. Write a program that prints the alphabet in lowercase, and then in uppercase, followed by a new line.<br />

* You can only use the `putchar` function (every other function (`printf`, `puts`, etc…) is forbidden)
* All your code should be in the `main` function
* You can only use `putchar` three times in your code
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-print_alphabets.c -o 3-print_alphabets
julien@ubuntu:~/$ ./3-print_alphabets | cat -e
abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ$
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * a program that print Alphbt on minus and cap
 * @void: no parameter
 * Return: 0
 **/
int main(void)
{
	int Alph;

	Alph = 'a';

	while (Alph >= 'a' || Alph <= 'Z')
	{
		putchar(Alph);
		Alph++;

		if (Alph > 'z')
			Alph = 'A';
	}
	putchar('\n');

	return (0);
}
```
## 4. Write a program that prints the alphabet in lowercase, followed by a new line.<br />

* Print all the letters except `q` and `e`
You can only use the `putchar` function (every other function (`printf`, `puts`, etc…) is forbidden)
All your code should be in the `main` function
You can only use `putchar` twice in your code
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-print_alphabt.c -o 4-print_alphabt
julien@ubuntu:~/$ ./4-print_alphabt 
abcdfghijklmnoprstuvwxyz
julien@ubuntu:~/$ ./4-print_alphabt | grep [eq]
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * Alphabet that skip the 'q' and 'e'
 * @void: no parameter
 * Return: 0
 */
int main(void)
{
	int Alph;

	for (Alph = 'a'; Alph != 'z' + 1; Alph++)
	{
		if (Alph == 'q' || Alph == 'e')
			continue;

		putchar(Alph);
	}
	putchar('\n');

	return (0);
}
```
## 5. Write a program that prints all single digit numbers of base 10 starting from 0, followed by a new line.<br />

* All your code should be in the main function
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-print_numbers.c -o 5-print_numbers
julien@ubuntu:~/$ ./5-print_numbers 
0123456789
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * print numbers 1 to 9
 * @void: no parameters
 * Return: 0
 */
int main(void)
{
	int n;

	n = '0';

	while (n < '9' + 1)
	{
		putchar(n);
		n++;
	}
	putchar('\n');

	return (0);
}
```
## 6. Write a program that prints all single digit numbers of base 10 starting from 0, followed by a new line.<br />

* You are not allowed to use any variable of type `char`
You can only use the `putchar` function (every other function (`printf`, `puts`, etc…) is forbidden)
You can only use putchar twice in your code
All your code should be in the `main` function
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 6-print_numberz.c -o 6-print_numberz
julien@ubuntu:~/$ ./6-print_numberz 
0123456789
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * print numbers 1 to 9
 * @void: no parameters
 * Return: 0
 */
int main(void)
{
	int n;

	n = '0';

	while (n < '9' + 1)
	{
		putchar(n);
		n++;
	}
	putchar('\n');

	return (0);
}
```
## 7. Write a program that prints the lowercase alphabet in reverse, followed by a new line.<br />

* You can only use the `putchar` function (every other function (`printf`, `puts`, etc…) is forbidden)
All your code should be in the `main` function
You can only use `putchar` twice in your code
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 7-print_tebahpla.c -o 7-print_tebahpla
julien@ubuntu:~/$ ./7-print_tebahpla
zyxwvutsrqponmlkjihgfedcba
julien@ubuntu:~/$
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * print the alphabet in reverse
 * @void: no parameter
 * Return: 0
 */
int main(void)
{
	int Alph;

	Alph = 'z';

	while (Alph >= 'a')
	{
		putchar(Alph);
		Alph--;
	}
	putchar('\n');

	return (0);
}
```
## 8. Write a program that prints all the numbers of base 16 in lowercase, followed by a new line.<br />

* You can only use the `putchar` function (every other function (`printf`, `puts`, etc…) is forbidden)
All your code should be in the `main` function
You can only use `putchar` three times in your code
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 8-print_base16.c -o 8-print_base16
julien@ubuntu:~/$ ./8-print_base16
0123456789abcdef
julien@ubuntu:~/$
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * print numbers 1 to 9
 * @void: no parameters
 * Return: 0
 */
int main(void)
{
	int n;

	n = -1;

	while (n <= 15)
	{
		putchar('1' + n);
		n++;

		if (n >= 9)
		{
			n = 'a';

			while (n != 'g')
			{
				putchar(n);
				n++;
			}
		}
	}
	putchar('\n');

	return (0);
}
```
## 9. Write a program that prints all possible combinations of single-digit numbers.<br />

* Numbers must be separated by `,`, followed by a space
* Numbers should be printed in ascending order
* You can only use the `putchar` function (every other function (`printf`, `puts`, etc…) is forbidden)
* All your code should be in the `main` function
You can only use `putchar` four times maximum in your code
You are not allowed to use any variable of type `char`
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 9-print_comb.c -o 9-print_comb
julien@ubuntu:~/$ ./9-print_comb | cat -e
0, 1, 2, 3, 4, 5, 6, 7, 8, 9$
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * print num ascending order
 * @void: no parameters
 * Return: 0
 */
int main(void)
{
	int n;

	n = 0;

	while (n <= 9)
	{
		putchar((n % 10) + '0');
		if (n == 9)
			break;

		n++;

		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
```
## 10. Write a program that prints all possible different combinations of two digits.<br />

* Numbers must be separated by `,`, followed by a space
* The two digits must be different
* `01` and `10` are considered the same combination of the two digits `0` and `1`
* Print only the smallest combination of two digits
* Numbers should be printed in ascending order, with two digits
* You can only use the `putchar` function (every other function (`printf`, `puts`, etc…) is forbidden)
* You can only use `putchar` five times maximum in your code
* You are not allowed to use any variable of type `char`
* All your code should be in the `main` function
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-print_comb3.c -o 100-print_comb3
julien@ubuntu:~/$ ./100-print_comb3
01, 02, 03, 04, 05, 06, 07, 08, 09, 12, 13, 14, 15, 16, 17, 18, 19, 23, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 56, 57, 58, 59, 67, 68, 69, 78, 79, 89
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int i, j;

	for (i = 0; i <= 8; i++)
	{

		for (j = 0; j <= 9; j++)
		{
			if (j > i)
			{
				putchar(i + '0');
				putchar(j + '0');
			}
			else
				continue;

			if (i == 8 && j == 9)
				putchar('\n');
			else
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	return (0);
}
```
## 11. Write a program that prints all possible different combinations of three digits.<br />

* Numbers must be separated by `,`, followed by a space
* The three digits must be different
* `012`, `120`, `102`, `021`, `201`, `210` are considered the same combination of the three digits `0`, `1` and `2`
* Print only the smallest combination of three digits
* Numbers should be printed in ascending order, with three digits
* You can only use the `putchar` function (every other function (`printf`, `puts`, etc…) is forbidden)
* You can only use `putchar` six times maximum in your code
* You are not allowed to use any variable of type `char`
* All your code should be in the `main` function
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 101-print_comb4.c -o 101-print_comb4
julien@ubuntu:~/$ ./101-print_comb4
012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int i, j, o;

	o = 0;

	while (o <= 7)
	{
		for (i = 0; i <= 8; i++)
		{
			for (j = 0; j <= 9; j++)
			{
				if ((j > i) && (i > o))
				{
					putchar(o + '0');
					putchar(i + '0');
					putchar(j + '0');
				}
				else
					continue;

				if (i == 8 && j == 9 && o == 7)
					putchar('\n');
				else
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
		o++;
	}
	return (0);
}
```
## 12. Write a program that prints all possible combinations of two two-digit numbers.<br />

+ The numbers should range from `0` to `99`
* The two numbers should be separated by a space
* All numbers should be printed with two digits. `1` should be printed as `01`
* The combination of numbers must be separated by comma, followed by a space
* The combinations of numbers should be printed in ascending order
* `00 01` and `01 00` are considered as the same combination of the numbers `0` and `1`
* You can only use the putchar function (every other function (`printf`, `puts`, etc…) is forbidden)
* You can only use `putchar` eight times maximum in your code
* You are not allowed to use any variable of type `char`
* All your code should be in the `main` function
```
```
**SOLVED**
```

```
