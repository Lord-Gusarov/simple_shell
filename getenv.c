#include "shell.h"
/**
 * _getenv - gets a string representation of the specified
 * enviroment variable
 * @name: name of the variable
 * Return: NULL if variable not found, else a string of the value
 */
char *_getenv(const char *name)
{
	unsigned int i = 0, ii = 0, r_len = 0;
	char *result;

	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		for (ii = 0; environ[i][ii] == name[ii]; ii++)
		{
			if (environ[i][ii + 1] == '=')
			{
				if (name[ii + 1] == '\0')
				{
					ii += 2;
					for (r_len = ii; environ[i][r_len] != '\0'; r_len++)
						;
					r_len = r_len - ii;
					result = malloc(sizeof(char) * (r_len + 1));
					if (result == NULL)
						perror("Malloc failed in _getenv()");
					result[r_len] = '\0';
					while (r_len > 0)
					{
						r_len--;
						result[r_len] = environ[i][r_len + ii];
					}
					return (result);
				}
			}
		}
	}

	return (NULL);
}
