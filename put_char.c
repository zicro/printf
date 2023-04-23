#include "main.h"
/**
 * put_char - functio print char
 * @c: input
 * Return: 1
 */
int put_char(va_list c)
{
	cha ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}
