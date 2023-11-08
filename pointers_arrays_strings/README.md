# This is all about pointers, strings and arrays

0. > write a function that points a var to update to 98
	* Prototype: 'void reset_to_98(int *n);'
```
	*n = 98;
```

1. > write a function that swaps the values of two integers
	* Prototype: `void swap_int(int *a, int *b);`
```
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
```

2. > write a function that return the length of a string
	*Prototype: `int _strlen(char *s);`
```
	int c;

	for (c = 0; *s != '\0' ; s++)
		c++;

	return (c);
```
