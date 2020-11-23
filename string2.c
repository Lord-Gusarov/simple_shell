#include "_string.h"

/**
 * intToStr - converts an int number to a string
 * @n: number to convert;
 * Return: pointer to new string representation
 */
char *intToStr(unsigned int n)
{
	char r_snum[15] = {'\0'};
	char num[15] = {'\0'};
	int i = 0, ii = 0;

	if (n == 0)
		return ("0");

	while (n != 0)
	{
		r_snum[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	for (i--, ii = 0; i >= 0; i--, ii++)
	{
		num[ii] = r_snum[i];
	}

	return (_strdup(num));
}

/**
 *_strcmp - compares two strings;
 *@s1: first string to compare
 *@s2: second string to compare
 *
 *Return: a number less than, equal to or greater than zero if @s1 is less
 *than, equal or greater than @s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++)
		;
	return (s1[i] - s2[i]);
}

/**
 *_atoi - converts a string to an integer, the number in the string can be
 *preceded by an infinite number of characters
 *@s: string from which to substract the first ocurrance of a number
 *
 *Return: the first continous int in a string
 */
int _atoi(char *s)
{
	long int n = 0, sign = 1;
	int i, ch;

	/* strtd indicates if a conversion to integer has started*/
	int strtd = 0;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		ch = *(s + i);
		if (strtd && (ch < '0' || ch > '9'))
			break;
		if (ch == '-')
			sign *= -1;
		if (ch >= '0' && ch <= '9')
		{
			strtd = 1;
			n = n * 10 + (ch - 48) * sign;
		}
	}

	if (n > INT_MAX)
		return (-1);

	return (n);
}

/**
 * onlyDigits - determine if a string is composed only
 * of digits
 * @str: string to check
 * Return: 1 if just digits, 0 otherwise
 */
int onlyDigits(char *str)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
