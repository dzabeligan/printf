#include <string.h>
#include <unistd.h>

#include "print_helpers.h"

/**
 * buffered_print - puts constant format chars into buffer
 *
 * @str: string
 * @sLen: string length
 *
 * Return: number of printed
 */
int buffered_print(const char *str, int sLen)
{
	static int len;
	static char buffer[1024] = {'\0'};
	int writen = 0;
	int i = 0;

	if (sLen == -1)
	{
		writen = (write(1, buffer, len));
		len = 0;
		memset(buffer, 0, sizeof(buffer));
	}
	while (str && (str + i) && sLen--)
	{
		buffer[len++] = *(str + i++);
		if (len == 1024)
		{
			writen = (write(1, buffer, len));
			len = 0;
			memset(buffer, 0, sizeof(buffer));
		}
	}

	return (writen);
}

/**
 * print_space - print spaces
 * @len: number of spaces
 *
 *  Return: length of bytes written
 */
int print_space(unsigned int len)
{
	int plen = 0;

	while (len--)
		plen += buffered_print(" ", 1);
	return (plen);
}

/**
 * num_len - length of number
 * @n: number
 * @updater: callback function
 *
 * Return: length of number
 */
unsigned int num_len(
	unsigned long int n, unsigned long int (*updater)(unsigned long int num))
{
	unsigned int num_width = 1;

	while (updater(n) > 0)
	{
		n = updater(n);
		num_width++;
	}
	return (num_width);
}
