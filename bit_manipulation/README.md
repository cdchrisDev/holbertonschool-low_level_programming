# C - Bit manipulation
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

