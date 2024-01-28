# C - Bit manipulation
### Resources: 
# Binary left and right shift
## It is basicaly used to multiply `left` or divide `right` by the bit sequence
**Binary representation of 22 int**<br />
```
N = 22;  //left and right shift means we change the position of certain bit
**EXAMPLE**
[0][0][0][1][0][1][1][0]
// shifting 22, 1 position to the left. Let us represent 44 in binary 
[0][0][1][0][1][1][0][0] //left shit change the first bit to set it at the end
**IN PROGRAM**
N = N << 1; // N is equal to N shifted 1 position to the left (1 can be any int)
N = N << i; N = N * (2^i);
```
**AND operator (&)**<br />
Check if two operands are set to 1, if so. The corresponding bits are 1.
```
int main(void) {
unsigned int number1 = 65535;
unsigned int mask = 1;
puts("The result of combining the following");
displayBits(number1);
displayBits(mask);
puts("using the bitwise AND operator & is");
displayBits(number & mask);
======= OUTPUT ==========
The result of combining the following
65535 = 00000000 00000000 11111111 11111111
    1 = 00000000 00000000 00000000 00000000
using the bitwise AND operator & is
    1 = 00000000 00000000 00000000 00000001
```
**OR bitwise inclusive OR (|)**<br />
check if at least 1 operand is set to 1
```
number1 = 15;
unsigned int setBits = 241;
puts("The result of combining the following");
displayBits(number1);
displayBits(setBits);
puts("using the bitwise incluse OR operator |is");
displayBits(number | setBits);
========== OUTPUT ==============
The result of combining the following
 15 = 00000000 00000000 00000000 00001111
241 = 00000000 00000000 00000000 11110001
using the bitwise inclusive OR operator | is
255 = 00000000 00000000 00000000 11111111
```
**bitwise exclusive ZOR (^)**<br />
Check if the corresponding bits are different
```
number1 = 139;
unsigned int number2 = 199;
puts("The result of combining the following");
displayBits(number1);
displayBits(number2);
puts("using the bitwise exclusive ZOR (^) is");
displayBits(number ^ number);
=========== OUTPUT ==============
The result of combining the following
139 = 00000000 00000000 00000000 10001011
199 = 00000000 00000000 00000000 11000111
using the bitwise exclusive OR operator ^ is
 76 = 00000000 00000000 00000000 01001100
```
**Bitwise complement (~) operator**<br />
flip the bits
```
number1 = 21845;
puts("The one's complement of");
displayBits(number1);
puts("is);
displayBits(~number);
============ OUTPUT ===============
The one's complement of
     21845 = 00000000 00000000 01010101 01010101
is
4294945450 = 11111111 11111111 10101010 10101010
```
# Task
## 0. Write a function that converts a binary number to an unsigned int.
* **Prototype**: `unsigned int binary_to_uint(const char *b);`
* where `b` is pointing to a string of `0` and `1` chars
* **Return**: the converted number, or `0` if
	* there is one or more chars in the string b that is not 0 or 1
	* `b` is `NULL`
```
julien@ubuntu:~/Binary$ cat 0-main.c
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned int n;

    n = binary_to_uint("1");
    printf("%u\n", n);
    n = binary_to_uint("101");
    printf("%u\n", n);
    n = binary_to_uint("1e01");
    printf("%u\n", n);
    n = binary_to_uint("1100010");
    printf("%u\n", n);
    n = binary_to_uint("0000000000000000000110010010");
    printf("%u\n", n);
    return (0);
}
julien@ubuntu:~/Binary$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-binary_to_uint.c -o a
julien@ubuntu:~/Binary$ ./a 
1
5
0
98
402
julien@ubuntu:~/Binary$ 
```
**SOLVED**
```
#include "main.h"
/**
 * binary_to_uint - a func to convert from binary to uint
 * @b: string of 0 or 1 char
 * Return: uint
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;
	int base = 1, i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i + 1] != '\0'; i++)
		if (b[i] != '0' && b[i] != '1')
			return (0);

	while (i >= 0)
	{
		res += ((b[i] - '0') * base);
		base *= 2;
		i--;
	}
	return (res);
}
```
## Write a function that prints the binary representation of a number.
* **Prototype**: `void print_binary(unsigned long int n);`
* **Format**: see example
* You are not allowed to use arrays
* You are not allowed to use `malloc`
* You are not allowed to use the `%` or `/` operators
```
julien@ubuntu:~/Binary$ cat 1-main.c 
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_binary(0);
    printf("\n");
    print_binary(1);
    printf("\n");
    print_binary(98);
    printf("\n");
    print_binary(1024);
    printf("\n");
    print_binary((1 << 10) + 1);
    printf("\n");
    return (0);
}
julien@ubuntu:~/Binary$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-print_binary.c _putchar.c -o b
julien@ubuntu:~/Binary$ ./b 
0
1
1100010
10000000000
10000000001
julien@ubuntu:~/Binary$ 
```
**SOLVED**
```
#include "main.h"
/**
 * print_binary - a func to print binary of a n
 * @n: integer
 * Return: void
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	_putchar((n & 1) + '0');
}
```
## 2. Write a function that returns the value of a bit at a given index.
* **Prototype**: `int get_bit(unsigned long int n, unsigned int index);`
* where `index` is the index, starting from `0` of the bit you want to get
* **Returns**: the value of the bit at index `index` or `-1` if an error occured
```
julien@ubuntu:~/Binary$ cat 2-main.c
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int n;

    n = get_bit(1024, 10);
    printf("%d\n", n);
    n = get_bit(98, 1);
    printf("%d\n", n);
    n = get_bit(1024, 0);
    printf("%d\n", n);
    return (0);
}
julien@ubuntu:~/Binary$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-get_bit.c -o c    
julien@ubuntu:~/Binary$ ./c
1
1
0
julien@ubuntu:~/Binary$ 
```
**SOLVED**
```
#include "main.h"
/**
 * get_bit - a func to return value of a bit on index
 * @n: integer
 * @index: the index
 * Return: integer
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (sizeof(n) * 8 < index)
		return (-1);

	n >>= index;
	if ((n & 1) == 1)
		return (1);
	else
		return (0);
}
```
## 3. Write a function that sets the value of a bit to 1 at a given index.
* **Prototype**: `int set_bit(unsigned long int *n, unsigned int index);`
* where `index` is the index, starting from `0` of the bit you want to set
* **Returns**: `1` if it worked, or `-1` if an error occurred
```
julien@ubuntu:~/Binary$ cat 3-main.c
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned long int n;

    n = 1024;
    set_bit(&n, 5);
    printf("%lu\n", n);
    n = 0;
    set_bit(&n, 10);
    printf("%lu\n", n);
    n = 98;
    set_bit(&n, 0);
    printf("%lu\n", n);
    return (0);
}
julien@ubuntu:~/Binary$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-set_bit.c -o d
julien@ubuntu:~/Binary$ ./d
1056
1024
99
julien@ubuntu:~/Binary$ 
```
**SOLVED**
```
#include "main.h"
/**
 * set_bit - func that sets the value of a bit to 1
 * @n: integer
 * @index: the index
 * Return: 1 or 0 if fail
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i = 1;

	if (sizeof(n) * 8 < index)
		return (-1);

	i <<= index;
	*n |= i;
	return (1);
}
```
## 4. Write a function that sets the value of a bit to 0 at a given index.
* **Prototype**: `int clear_bit(unsigned long int *n, unsigned int index);`
* where `index` is the index, starting from `0` of the bit you want to set
* **Returns**: `1` if it worked, or `-1` if an error occurred
```
julien@ubuntu:~/Binary$ cat 4-main.c
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned long int n;

    n = 1024;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 0;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 98;
    clear_bit(&n, 1);
    printf("%lu\n", n);
    return (0);
}
julien@ubuntu:~/Binary$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-clear_bit.c -o e
julien@ubuntu:~/Binary$ ./e
0
0
96
julien@ubuntu:~/Binary$ 
```
**SOLVED**
```
#include "main.h"
/**
 * clear_bit - a func that sets bit to 0
 * @n: integer
 * @index: the index
 * Return: 1 or 0 if it fails
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i = 1;

	if (sizeof(n) * 8 < index)
		return (-1);

	i <<= index;
	*n &= ~i;
	return (1);
}
```
## 5. Write a function that returns the number of bits you would need to flip to get from one number to another.
* **Prototype**: unsigned int flip_bits(unsigned long int n, unsigned long int m);
* You are not allowed to use the `%` or `/` operators
```
julien@ubuntu:~/Binary$ cat 5-main.c
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned int n;

    n = flip_bits(1024, 1);
    printf("%u\n", n);
    n = flip_bits(402, 98);
    printf("%u\n", n);
    n = flip_bits(1024, 3);
    printf("%u\n", n);
    n = flip_bits(1024, 1025);
    printf("%u\n", n);
    return (0);
}
julien@ubuntu:~/Binary$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-flip_bits.c -o f
julien@ubuntu:~/Binary$ ./f
2
5
3
1
julien@ubuntu:~/Binary$ 
```
**SOLVED**
```
#include "main.h"
/**
 * flip_bits - a func that returs a numbers you need to flip
 * @n: integer
 * @m: integer
 * Return: int
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int t;
	int i = 0;

	t = n ^ m;
	while (t >= 1)
	{
		if ((t & 1) == 1)
		i++;
		t >>= 1;
	}
	return (i);
}
```

## EXTRA CLASSWORK ASSIGNMENT
> Write a program to generate data for N students. Use structure to create numeric ID and points (MAX 100) as 2 separate numbers of the structure. Ramdomly generate data for N students. Dislay both the ID and the points of the student who has received highest point. Write three separate functions to complete program:
1. `generateStudentData()` Input is array of students.<br />
2. `printStudentInfo()`input is a single student<br />
3. `getTopStudent()` input is array of students and output is a single student
<br /> sda
