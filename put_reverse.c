#include "main.h"

/**
 * put_reverse - prints reverse order of characters
 * @r: string to be printed in reverse order
 *
 * Return: chars printed number
 */
int put_reverse(va_list r)
{
	char *str;
	int i, c = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		c++;
	}
	return (c);
}
