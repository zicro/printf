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
