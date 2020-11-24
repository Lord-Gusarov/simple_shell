#include "shell.h"
/**
 * execBuiltIn -if the first token in the input array o srtrings corresponds
 * to a Built-In command this function will tke care of executing it
 * as needed
 * @p_name: name that ws used to call to run ourshell
 * @input: array of strings containing all arguments last given to oursehll
 * @p_cnt: the current number of the procces being run,
 * info needed to write certain errors
 *
 * Return: O if the program should STOP running, positive number otherwise
 */
int execBuiltIn(char *p_name, char **input, unsigned int p_cnt)
{
	if (_strcmp(input[0], "env") == 0)
		env();
	else if (_strcmp(input[0], "exit") == 0)
	{
		return (!(_exit_(p_name, input, p_cnt)));
	}
	return (1);
}
/**
 * env - Built_in that prints all the enviromen varibales to stdout
 */
void env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * _exit_ - validates the inputs, if the arguments are correct then the
 * function makes sure everything is done to properly clear Ourshell
 * before exiting
 * @p_name: the way in which Ourshell was call to action
 * @input: array of strings containing the arguments last passed to Ourshel
 * @p_cnt: current procces number of Ourshell
 *
 * Return: 0 if conditions to exit were not met
 */
int _exit_(char *p_name, char **input, unsigned int p_cnt)
{
	char *message = ": exit: Illegal number: ";
	int code = 0;
	char *error = NULL;
	char *sN = NULL;

	if (input[1] != NULL)
	{
		if (!onlyDigits(input[1]) || (_atoi(input[1]) == -1))
		{
			sN = intToStr(p_cnt);
			error = concatenator(6, p_name, ": ", sN, message, input[1], "\n");
			write(STDERR_FILENO, error, _strlen(error));
			sfree(&sN);
			sfree(&error);
			return (0);
		}
		else
		{
			code = _atoi(input[1]);
		}
	}
	else if (p_cnt > 1)
	{
		code = exit_code;
	}
	freeStrArr(input);
	exit(code);
}
