#include "_string.h"

/**
 *_strlen - calculates the lenght of a string
 *@s: pointer to the string
 *
 *Return: length of the string
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; *(s + len) != '\0'; len++)
		;

	return (len);
}

/**
 * _strdup - returns a pointer to a new string which is a duplicate
 * of the string str.
 * @str: string to duplicate
 *
 * Return: On success, the _strdup function returns a pointer to the duplicated
 * string. It returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	int len;
	char *dup;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
		;
	dup = malloc((sizeof(char) * (len + 1)));
	if (dup == NULL)
		return (NULL);

	while (len >= 0)
	{
		dup[len] = str[len];
		len--;
	}

	return (dup);
}


/**
 * _wc - word count in a string, separated by chars in @delims
 * @str: string to analyze
 * @delims: list of chars that separate a word/token
 * Return: count of words/tokens in a string
 */
int _wc(char *str, char *delims)
{
	int i = 0, wc = 0, flag = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (strHasChar(delims, str[i]))
			flag = 1;
		else if (flag)
		{
			wc++;
			flag = 0;
		}
	}
	return (wc);
}
/**
 * strHasChar - determines of a string contains certain char
 * @str: string to check
 * @c: char to look for
 * Return: 1 if it contins the speciifed char, else 0
 */
int strHasChar(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}

	return (0);
}
/**
 * _strtok - splits a string into words/tokens
 * @str: string to be splitted
 * @delims: set of char that can separate aword/token
 *
 * Return: The function returns a pointer to an array of strings (words)
 * NULL if str == NULL or str == ""
 */
char **_strtok(char *str, char *delims)
{
	char **m = NULL;
	int i, ii, w_idx = 0, wl = 0, wc = 0;

	if (str == NULL || str == '\0') /*keep eye out for last comparison*/
		return (NULL);
	wc = _wc(str, delims);
	if (wc > 0)
		m = malloc(sizeof(char *) * (wc + 1));
	if (m == NULL)
		return (NULL);
	m[wc] = NULL;
	for (i = 0; str[i] != '\0'; wl = 0)
	{
		while (str[i] != '\0' && strHasChar(delims, str[i]))
			i++;
		while (str[i] != '\0' && !strHasChar(delims, str[i]))
		{
			wl++, i++;
		}
		if (wl > 0)
		{
			m[w_idx] = malloc(sizeof(char) * (wl + 1));
			if (m[w_idx] == NULL)
			{
				while (w_idx > 0)
					free(m[--w_idx]);
				free(m);
				return (NULL);
			}
			m[w_idx][wl] = '\0';
			for (ii = 0; ii < wl; ii++)
				m[w_idx][ii] = str[i - (wl - ii)];
			w_idx++;
		}
	}

	return (m);
}
