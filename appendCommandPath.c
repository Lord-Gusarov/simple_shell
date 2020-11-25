#include "shell.h"

/**
 * appendCommandPath - appends the first subpath where the command was found
 * @input: arguments read from stdin
 * Return: 1 if command path is found to be valid, otherwise 0
 */
int appendCommandPath(char **input)
{
	struct stat st;
	char *check = NULL, *path = NULL, **tokens = NULL;
	int i = 0, idx_cwd = 0, valid = 0;

	if (input[0][0] == '.' || input[0][0] == '/')
		if (stat(*input, &st) == 0)
			return (1);

	path = _getenv("PATH");
	tokens = _strtok(path, ":");
	idx_cwd = locateEmptyDir(path);
	if (!(tokens == NULL || path == NULL))
	{
		for (i = 0; tokens[i] != NULL; i++)
		{
			if (idx_cwd == i)
			{
				if (stat(*input, &st) == 0)
				{
					valid = 1;
					break;
				}
			}
			check = concatenator(3, tokens[i], "/", *input);
			if (stat(check, &st) == 0)
			{
				sfree(&input[0]);
				input[0] = _strdup(check);
				valid = 1;
				break;
			}
			sfree(&check);
		}
	}
	sfree(&check);
	sfree(&path);
	freeStrArr(tokens);
	return (valid);
}

/**
 * locateEmptyDir - checks a string of directories separated by a
 * ':' for the existance of the leading empty directory, trailing empty
 * directory or its existence somewhere in between.
 * @str: string representation of a list of directories separated
 * by a ':'
 * Return: positon of the first occurence of an empty directory
 * or -1 if none is found. (postions values starting at 0)
 */
int locateEmptyDir(char *str)
{
	int l = 0;
	int i = 0;

	if (str == NULL)
		return (l);

	if (*str == ':')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == ':')
		{
			l++;
			if (str[i + 1] == ':')
				return (l);
		}
		i++;
	}
	if (i > 0)
		if (str[i - 1] == ':')
			return (l);

	return (-1);
}
