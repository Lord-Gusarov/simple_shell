#include "shell.h"

/**
 * main - takes care of running -ourshell-
 * @ac: amount of argumments passed
 * @av: arguments passed form the terminal as an array of strings
 * Return: 0 if executed without errors
 */
int main(__attribute__((unused)) int ac, char **av)
{
	unsigned int p_cnt = 0;
	char **input = NULL;
	int status;

	signal(SIGINT, catch_c_c);
	do {
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		p_cnt++;
		if (getcommand(&input) > 1)
		{
			if (builtin(*input))
				execBuiltIn(av[0], input, p_cnt);
			else
			{
				if (appendCommandPath(input) == 1)
				{
					if (fork() == 0)
					{
						execve(input[0], input, NULL);
						freeStrArr(input);
						exit(127);
					}
					else
					{
						wait(&status);
						exit_code = WEXITSTATUS(status);
					}
				}
				else
					commandNotFound(av[0], p_cnt, *input);
			}
		}
		freeStrArr(input);
		input = NULL;
	} while (1);
	exit(exit_code);
}
