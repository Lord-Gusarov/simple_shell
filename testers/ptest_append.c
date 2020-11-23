#include "shell.h"


int main(void)
{
	char *command = "pwd hs";
	char **toks = _strtok(command, " ");

	printf("before toks[0] --> %s\n", toks[0]);

	appendCommandPath(&toks[0]);

	printf("full path --> %s\n", toks[0]);

	freeStrArr(toks);
	


	return (0);
}
