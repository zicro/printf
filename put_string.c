#include "main.h"
/**
 * put_string - string printer
 * @s: string to print
 * Return: char count
 */
int put_string(va_list s)
{
	int c;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (c = 0; str[c]; c++)
	{
		_putchar(str[c]);
	}
	return (c);
}
