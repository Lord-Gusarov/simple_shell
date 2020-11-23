#include "shell.h"

/**
 * eatSapces - finds and deletes spaces or tabs in the beggining of a string
 * @line: string to be analyzed for spaces
 * Return: new allocated memory with string and no spaces
 */

char *eatSpaces(char *line)
{
	int length;
	int idx = 0, count = 0;
	char *strHolder;

	length = _strlen(line);
	strHolder = malloc(sizeof(char) * (length + 1));
	if (strHolder == NULL)
		return (NULL);

	while (*(line + count) == ' ' || *(line + count) == '\t')
		count++;
	while (*(line + count) != '\0')
	{
		*(strHolder + idx) = *(line + count);
		count++;
		idx++;
	}
	*(strHolder + idx) ='\0';

	return (strHolder);
}
