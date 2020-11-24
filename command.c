#include "shell.h"
#define BUFF_SIZE 300
/**
 * commandNotFound - handles the error message when a command
 * read from input is not found
 * @str1: how the SHELL was invoked
 * @cnt: process count
 * @str2: the command not found
 */
void commandNotFound(char *str1, unsigned int cnt, char *str2)
{
	char *scnt = intToStr(cnt);
	char *s = ": ";
	char *error = concatenator(7, str1, s, scnt, s, str2, s, "not found\n");

	write(STDERR_FILENO, error, _strlen(error));
	fflush(stdout);
	sfree(&error);
	sfree(&scnt);
}

/**
 * getcommand - fetches from the STDIN_FILENO the next command for the shell
 * @buffer: buffer pointer to where the command should be stored
 * Return:-1 in failure, else the amount of chars read without the ending '\n'
 */
int getcommand(char ***buffer)
{
	size_t bufsize;
	int chars_rd = 0;
	char *line = NULL, *line2 = NULL;

	freeStrArr(*buffer);

	chars_rd = getline(&line, &bufsize, stdin);
	if (chars_rd == EOF)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		sfree(&line);
		exit(exit_code);
	}
	line2 = eatSpaces(line);
	sfree(&line);
	chars_rd = _strlen(line2);
	*buffer = _strtok(line2, " \t\n");
	sfree(&line2);
	return (chars_rd);
}
/**
 * builtin - determines if the firts token from input is a 'built-in' command
 * @token: first token from input
 * Return: 1 if it is, 0 otherwise
 */
int builtin(char *token)
{
	int i = 0;
	char *b[] = {"env", "exit", NULL};

	while (b[i] != NULL)
	{
		if (_strcmp(token, b[i]) == 0)
		{
			return (1);
		}
		i++;
	}

	return (0);
}

