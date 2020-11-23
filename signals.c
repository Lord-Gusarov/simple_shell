#include "shell.h"

/**
 * catch_c_c - handles what should happen the the C-c
 * combo keys are pressed
 * @sig: reference to the signal being handled
 */
void catch_c_c(int sig)
{
	write(STDOUT_FILENO, "\n$ ", 3);
	signal(sig, catch_c_c);
}

/**
 * catch_c_d - handles the end of file keyboard combination
 * @sig: reference to the sginal being handled
 */
void catch_c_d(int sig)
{
	fflush(stdin);
	signal(sig, catch_c_d);
}

