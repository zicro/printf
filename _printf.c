#include "main.h"

/**
 * _printf - prints anything
 * @format: args passed to func
 *
 * Return: chars number that was printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, cnt = 0;
	va_list vlist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(vlist, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			cnt++;
		}
		if (!format[i])
			return (cnt);
		f = format_checker(&format[i + 1]);
		if (f != NULL)
		{
			cnt = cnt + f(vlist);
			i = i + 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		cnt++;
		if (format[i + 1] == '%')
			i = i + 2;
		else
			i++;
	}
	va_end(vlist);
	return (cnt);
}

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
		{"S", put_non_printable},
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
