#include "shell.h"

/**
 * _getline - gets next line in depending if the shell is working in
 * interactive mode vs NON-interactive mode
 * @lineptr: adress of the buffer to write to
 * @n:desired amount of chars to read
 * @fd: file descriptor
 * Return: amount of chars read
 */
ssize_t _getline(char **lineptr, size_t n, int fd)
{
	if (isatty(fd) == 1) /*Running interactively*/
		return (_igetline(lineptr, n, fd));

	return (_ngetline(lineptr, n, fd));
}

/**
 * _igetline - gets next line in interactive mode
 * @lineptr: adress of the buffer to write to
 * @n:desired amount of chars to read
 * @fd: file descriptor
 * Return: amount of chars read
 */
ssize_t _igetline(char **lineptr, size_t n, int fd)
{
	char *line = NULL;
	ssize_t ch_rd = 0;

	line = malloc(n);
	ch_rd = read(fd, line, n);
	if (ch_rd < 0)
		return (EOF);
	line[ch_rd] = '\0';

	*lineptr = line;
	return (ch_rd);

}

/**
 * _ngetline - gets next line in NON-interactive mode
 * @lineptr: adress of the buffer to write to
 * @n:desired amount of chars to read
 * @fd: file descriptor
 * Return: amount of chars read
 */
ssize_t _ngetline(char **lineptr, size_t n, int fd)
{
	static ssize_t ch_rd, idx_b;
	static char *buffer = NULL, d1 = '\n', d2 = ';';
	char *line = NULL;
	ssize_t lcnt = 0, idx = 0;

	if (buffer == NULL)
	{
		buffer = malloc(n);
		ch_rd = read(fd, buffer, n);
		if (ch_rd <= 0)
		{
			free(buffer);
			return (EOF);
		}
		buffer[ch_rd] = '\0';
	}
	if (idx_b == ch_rd)
	{
		free(buffer);
		return (EOF);
	}
	while (buffer[idx_b] != d1 && buffer[idx_b] != d2 && idx_b < ch_rd)
		lcnt++, idx_b++;
	if (buffer[idx_b] == d1 || buffer[idx_b] == d2)
		idx_b++, lcnt++;
	line = malloc(sizeof(char) * (lcnt + 1));
	line[lcnt] = '\0';

	for (idx = 0; idx < lcnt; idx++)
		line[idx] = buffer[idx_b - (lcnt - idx)];

	*lineptr = line;
	return (lcnt);
}
