#include "main.h"

/**
 * put_unprintable - prints a non-printable ascii chars
 * @S: string to be printed
 *
 * Return: printed number of chars
 */
int put_unprintable(va_list S)
{
	unsigned int i;
	int c = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			c += 2;
			c += hex_put(str[i]);
		}
		else
		{
			_putchar(str[i]);
			c++;
		}
	}
	return (c);
}
