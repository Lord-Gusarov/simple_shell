#include "shell.h"

int main(int ac, char **av)
{
	char *value ;
	if (ac >= 1)
		value = _getenv(av[1]);
	printf("%s\n", value == NULL ? "(nil)": value);
	if(!value)
		free (value);
	return (0);
}
