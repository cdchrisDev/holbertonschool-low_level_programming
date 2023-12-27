# C - More malloc, free
### Resources
* [Do I cast the result of malloc?](https://intranet.hbtn.io/rltoken/I9aeMNSqr7qd27vXCJXXJQ)
## Learning Objectives
* How to use the exit function
	* **Example 1**: Program to demonstrate the usage of the EXIT_SUCCESS or exit(0) function
```
#include <stdio.h>
#include <stdlib.>
int main ()
{
printf ( " Start the execution of the program. \ n");
printf (" Exit from the program. \ n ");
// use exit (0) function to successfully execute the program.
exit (0);
```
* What are the functions `calloc` and `realloc` from the standard library and how to use them
	* `calloc` *Contiguous allocation*, allocate mem eahc block with value `0`. It has tow parameters.<br /> `ptr = (cast-type*)calloc(n, element-size);`
