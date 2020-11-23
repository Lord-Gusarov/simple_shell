#include "shell.h"
#include "getenv.c"
#include "string1.c"

int main(void)
{
	char *path = _getenv("PATH");
	char **tokens = _strtok(path, ":");

	while (*tokens != NULL)
	{
		printf("%s\n", *tokens);
		tokens++;
	}

	return (0);
}
