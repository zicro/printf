#include "main.h"

/**
 * format_checker - check the format specifier if it's valid
 * @format: format specifier
 *
 * Return: pointer to func if non then NULL
 */
static int (*format_checker(const char *format))(va_list)
{
	unsigned int j;
	puts_list p[] = {
		{"c", put_char},
		{"s", put_string},
		{"i", put_integer},
		{"d", put_decimal},
		{"u", put_unsigned},
		{"b", put_binary},
		{"o", put_octal},
		{"x", put_lower_hex},
		{"X", put_upper_hex},
		{"p", put_address},
		{"S", put_unprintable},
		{"r", put_reverse},
		{"R", put_rot13},
		{NULL, NULL}
	};

	for (j = 0; p[j].type != NULL; j++)
	{
		if (*(p[j].type) == *format)
		{
			break;
		}
	}
	return (p[j].func);
}
