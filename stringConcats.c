#include "_string.h"

/**
 * str_concat - concatenates two strings
 * @s1: first string to copy
 * @s2: string to add righgt behind @s1
 *
 * Return: <Del>point to a newly allocated space in memory which contains
 * the contents of s1, followed by the contents of s2, and
 * null terminated, NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int i, m_idx, m_len = 0;
	char *m;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++, m_len++)
		;
	for (i = 0; s2[i] != '\0'; i++, m_len++)
		;

	m = malloc(sizeof(char) * (m_len + 1));
	if (m == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		m[i] = s1[i];
	m_idx = i;
	for (i = 0; s2[i] != '\0'; i++, m_idx++)
		m[m_idx] = s2[i];
	m[m_idx] = '\0';

	return (m);
}

/**
 * concatenator - concatenates as many strings as desired
 * @n: the ammount of strings being passed to the function
*
 * Return: pointer newly allocated block with the all the string concatenated
 */
char *concatenator(unsigned int n, ...)
{
	char *newCon = NULL, *tmpCon = NULL, *nextVA = NULL;
	unsigned int i = 0;
	va_list list;

	if (n == 0)
		return (NULL);

	va_start(list, n);
	newCon = va_arg(list, char *);
	if (n > 1)
	{
		for (i = 1; i < n; i++)
		{
			nextVA = va_arg(list, char *);
			tmpCon = newCon;
			newCon = str_concat(newCon, nextVA);
			if (i > 1)          /*otherwise on the first loop 'newCon' is not*/
				sfree(&tmpCon); /*pointer than can be set free*/
		}
	}

	va_end(list);

	return (newCon);
}

