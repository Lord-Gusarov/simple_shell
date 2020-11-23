# SIMPLE_SHELL
---
Our Shell is meant to work as the santard /bash/sh regular Shell interface
and will accept commands given by the user, validate the input, look for
the existence of the command in the PATH and execute it or write to STDERR
in case of failure.
>Making this Simple_Shell is part of the Holberton School curriculum
for the 0920 Cohort.

# Compilation
This repository and its contents are meant to be compiled in the
following manner:

```
gcc -Wall -Werror -Wextra -pedantic \*.c -o hsh
```

For convenience the repo contains an executable script that will
compile it for you in this manner. To use the script just type:
```
./gcc_compile_hsh
```
# Running the Simple_Shell

Once compiled there are two ways to use the Simple_Shell, **Interactive**
and **NON-Interactive**

* **Interactive**
>The Simple_Shell waits to read input from *stdin*, validates.. processes
>the input and continuous looping until the 'buil-in' exit command is given.
```
.../somewhere$ ./hsh
$ /bin/ls
hsh main.c shell.c
$ pwd
.../somewhere
$ exit
.../somewhere$
```

* **NON-Interactive**
>The Simple_Shell is unable to read from *stdin* but receives a defined
>sequence of commands and exits.
```
.../somewhere$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
.../somewhere$
.../somewhere$ cat test_ls_2
/bin/ls
/bin/ls
.../somewhere$
.../somewhere$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
.../somewhere$
```
# Testing

There is a folder called 'testers' where all files used to test
particular functions are kept. To use any of these files one would have
to swap the desired test with the *ourshell.c* file (*ourshell.c* contains
the *main* that controls the Simple_Shell) and compile the repo again in
one of the manners suggested above.

## Testing for Memory Leaks

Once the Simple_Shell has been compiled in one of the manners mentioned
above a thorought yet easy check for memory leaks using Valgrind is possible
by executing the *leaks_check* script in this repo.

```
./leaks_check
```
Using this scrip is equivalent to:
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./hsh
```
In both manners you'll be able to see a breakdown during runtime of the 
memory being allocated, being freed and if invalid reference are made
to freed pointers etc...

*Leaks in Child processes are not being tracked as they reports would
contain info about leaks from the commands getting executed. Ex 'ls'
trows many leaks which have nothing to do with our Simple_Shell*


