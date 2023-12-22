# C - Makefiles
### Resources
* [Makefile](https://www.google.com/search?q=makefile)
* [Makefiletutorial](https://intranet.hbtn.io/projects/2191)
## Learning objectives
* What are `make`, Makefiles
	* Makefile sets a set of rules to determine which parts of a program need to be recompile, and issues command to recompile them. • Makefile is a way of automating software building procedure and other complex tasks with dependencies.<br />

*  When, why and how to use Makefiles
	* to manage the dependencies of the source files of the programs during the compilation and linking (build) phase<br />

* What are rules and how to set and use them
	* A rule appears in the makefile and says when and how to remake certain files, called the rule's targets
	* Rules example: 
```
foo.o : foo.c defs.h       # module for twiddling the frobs
        cc -c -g foo.c
```
**Target:** `foo.o`<br/>

**Prerequisites:** `foo.c` and `defs.h`<br />

**Command:** `cc -c -g foo.c`<br />
* This rule says two things:

	* How to decide whether `foo.o` is out of date: it is out of date if it does not exist, or if either `foo.c` or `defs.h` is more recent than it.
	* How to update the file `foo.o`: by running cc as stated. The recipe does not explicitly mention defs.h, but we presume that `foo.c` includes it, and that is why `defs.h` was added to the prerequisites.<br />

* What are explicit and implicit rules
	* Explicit rules are instructions for specific files. Implicit rules are general instructions for files without explicit rules

* What are the most common / useful rules
```
target: prerequisites
        recipe
```
* What are variables and how to use them
	* Variables
	* Variables can only be strings. You'll typically want to use `:=`, but `=` also works. See Variables Pt 2.
	* Here's an example of using variables:
```
files := file1 file2
some_file: $(files)
	echo "Look at this variable: " $(files)
	touch some_file

file1:
	touch file1
file2:
	touch file2

clean:
	rm -f file1 file2 some_file
```
# Task
## 0. Create your first Makefile
Requirements:
* Name of the executable: `school`
* rules: `all`
	* The `all` rule builds you executable
* variables: none
```
julien@ubuntu:~/Makefiles$ make -f 0-Makefile 
gcc main.c school.c -o school
julien@ubuntu:~/Makefiles$ ./school 
j#0000000000000000000000000000000000000
j#000000000000000000@Q**g00000000000000
j#0000000000000000*]++]4000000000000000
j#000000000000000k]++]++*N#000000000000
j#0000000000000*C+++]++]++]J*0000000000
j#00000000000@+]++qwwwp=]++++]*00000000
j#0000000000*+++]q#0000k+]+]++]4#000000
j#00000000*C+]+]w#0000*]+++]+]++0000000
j#0000we+]wW000***C++]++]+]++++40000000
j#000000000*C+]+]]+]++]++]++]+q#0000000
j#0000000*]+]+++++++]++]+++]+++J0000000
j#000000C++]=]+]+]+]++]++]+]+]+]=000000
j#00000k+]++]+++]+]++qwW0000000AgW00000
j#00000k++]++]+]+++qW#00000000000000000
j#00000A]++]++]++]++J**0000000000000000
j#000000e]++]+++]++]++]J000000000000000
j#0000000A]++]+]++]++]++000000000000000
j#000000000w]++]+]++]+qW#00000000000000
j#00000000000w]++++]*0##000000000000000
j#0000000000000Ag]+]++*0000000000000000
j#00000000000000000we]+]Q00000000000000
j#0000000000000@@+wgdA]+J00000000000000
j#0000000000000k?qwgdC=]4#0000000000000
j#00000000000000w]+]++qw#00000000000000
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
julien@ubuntu:~/Makefiles$ 
```
**SOLVED**
```
all: 
	gcc main.c school.c -o school
```
## 1. Requirements:

* name of the executable: `school`
* rules: `all`
	* The `all` rule builds your executable
* variables: `CC`, `SRC`
	* `CC`: the compiler to be used
	* `SRC`: the `.c` files
```
julien@ubuntu:~/Makefiles$ make -f 1-Makefile
gcc main.c school.c -o school
julien@ubuntu:~/Makefiles$ make -f 1-Makefile
gcc main.c school.c -o school
julien@ubuntu:~/Makefiles$
```
**SOLVED**
```
CC = gcc
SRC = main.c school.c

all: $(SRC)
	$(CC) $(SRC) -o school
```
## 2. Create your first useful Makefile.

Requirements:

* name of the executable: `school`
* rules: `all`
	* The all rule builds your executable
* variables: `CC`, `SRC`, `OBJ`, `NAME`
`CC`: the compiler to be used
`SRC`: the `.c` files
`OBJ`: the `.o` files
`NAME`: the name of the executable
* The `all` rule should recompile only the updated source files
* You are not allowed to have a list of all the `.o` files
```
julien@ubuntu:~/Makefiles$ make -f 2-Makefile
gcc    -c -o main.o main.c
gcc    -c -o school.o school.c
gcc main.o school.o -o school
julien@ubuntu:~/Makefiles$ make -f 2-Makefile
gcc main.o school.o -o school
julien@ubuntu:~/Makefiles$ echo "/* School */" >> main.c
julien@ubuntu:~/Makefiles$ make -f 2-Makefile
gcc    -c -o main.o main.c
gcc main.o school.o -o school
julien@ubuntu:~/Makefiles$ 
```
**SOLVED**
```
CC = gcc
SRC = main.c school.c
OBJ = main.o school.o
NAME = school

all: $(SRC)
	$(CC) $(SRC) -o $(NAME)
```
## 3. Requirements:

* name of the executable: `school`
* rules: `all`, `clean`, `oclean`, `fclean`, `re`
	* `all`: builds your executable
	* `clean`: deletes all Emacs and Vim temporary files along with the executable
	* `oclean`: deletes the object files
	* `fclean`: deletes all Emacs and Vim temporary files, the executable, and the object files
	* `re`: forces recompilation of all source files
* variables: CC, SRC, OBJ, NAME, RM
	* `CC`: the compiler to be used
	* `SRC`: the `.c` files
	* `OBJ`: the `.o` files
	* `NAME`: the name of the executable
	* `RM`: the program to delete files
* The `all` rule should recompile only the updated source files
* The `clean`, `oclean`, `fclean`, re rules should never fail
* You are not allowed to have a list of all the `.o` files
```
julien@ubuntu:~//Makefiles$ ls -1
0-Makefile
1-Makefile
2-Makefile
3-Makefile
school.c
main.c
main.c~
m.h
julien@ubuntu:~/Makefiles$ make -f 3-Makefile
gcc    -c -o main.o main.c
gcc    -c -o school.o school.c
gcc main.o school.o -o school
julien@ubuntu:~/Makefiles$ make all -f 3-Makefile
gcc main.o school.o -o school
julien@ubuntu:~/Makefiles$ ls -1
0-Makefile
1-Makefile
2-Makefile
3-Makefile
school
school.c
school.o
main.c
main.c~
main.o
m.h
julien@ubuntu:~/Makefiles$ make clean -f 3-Makefile 
rm -f *~ school
julien@ubuntu:~/Makefiles$ make oclean -f 3-Makefile 
rm -f main.o school.o
julien@ubuntu:~/Makefiles$ make all -f 3-Makefile
gcc    -c -o main.o main.c
gcc    -c -o school.o school.c
gcc main.o school.o -o school
julien@ubuntu:~/Makefiles$ make fclean -f 3-Makefile 
rm -f *~ school
rm -f main.o school.o
julien@ubuntu:~/Makefiles$ make all -f 3-Makefile
gcc    -c -o main.o main.c
gcc    -c -o school.o school.c
gcc main.o school.o -o school
julien@ubuntu:~/Makefiles$ make all -f 3-Makefile
gcc main.o school.o -o school
julien@ubuntu:~/Makefiles$ make re -f 3-Makefile
rm -f main.o school.o
gcc    -c -o main.o main.c
gcc    -c -o school.o school.c
gcc main.o school.o -o school
julien@ubuntu:~/Makefiles$ 
```
**SOLVED**
```
CC = gcc
SRC = main.c school.c
OBJ = $(SRC:.c=.o) 
NAME = school
RM = rm -f

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean all
```
## 4. Requirements:

* name of the executable: `school`
* rules: `all`, `clean`, `fclean`, `oclean`, `re`
	* `all`: builds your executable
	* `clean`: deletes all Emacs and Vim temporary files along with the executable
	* `oclean`: deletes the object files
	* `fclean`: deletes all Emacs and Vim temporary files, the executable, and the object files
	* `re`: forces recompilation of all source files
* variables: `CC`, `SRC`, `OBJ`, `NAME`, `RM`, `CFLAGS`
	* `CC`: the compiler to be used
	* `SRC`: the `.c` files
	* `OBJ`: the .o files
	* `NAME`: the name of the executable
	* `RM`: the program to delete files
	* `CFLAGS`: your favorite compiler flags: `-Wall -Werror -Wextra -pedantic`
* The `all` rule should recompile only the updated source files
* The `clean`, `oclean`, `fclean`, re rules should never fail

* You are not allowed to have a list of all the `.o` files
```
julien@ubuntu:~/Makefiles$ make all -f 4-Makefile
gcc -Wall -Werror -Wextra -pedantic   -c -o main.o main.c
gcc -Wall -Werror -Wextra -pedantic   -c -o school.o school.c
gcc main.o school.o -o school
julien@ubuntu:~/Makefiles$ 
```
**SOLVED**
```
CC = gcc
SRC = main.c school.c
OBJ = $(SRC:.c=.o) 
NAME = school
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -pedantic

all: $(OBJ)
	$(CC) $(CLFAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean all
```
