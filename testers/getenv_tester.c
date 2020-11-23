#include "shell.h"
#include "getenv.c"

int main(void)
{
	printf("%s\n", _getenv("PATH"));
	return (0);
}

