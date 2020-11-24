#include "shell.h"

/**
 * main - takes care of running -ourshell-
 * @ac: amount of argumments passed
 * @av: arguments passed form the terminal as an array of strings
 * Return: 0 if executed without errors
 */
int main(__attribute__((unused)) int ac, char **av)
{
	pid_t my_pid;
	unsigned int p_cnt = 0;
	char **input = NULL;
	int valid_path = 0;

	signal(SIGINT, catch_c_c);

	do {
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		p_cnt++;
		if (getcommand(&input) > 1)
		{
			if (!builtin(*input))
			{
				valid_path = appendCommandPath(input);
				my_pid = fork();
				if (my_pid == 0)
				{
					if (!valid_path || (execve(input[0], input, NULL) == -1))
					{
						commandNotFound(av[0], p_cnt, *input);
						freeStrArr(input);
						exit(-1);
					}
				}
				else
					wait(NULL);
			}
			else
				execBuiltIn(av[0], input, p_cnt);
		}
		freeStrArr(input);
		input = NULL;
	} while (1);

	exit(-1);
}
