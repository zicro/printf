#include "main.h"

/**
 * put_octal - get the unsigned int into an octal format
 * @o: unsigned int to be printed
 *
 * Return: count of printed digits
 */
int put_octal(va_list o)
{
	unsigned int a[11];
	unsigned int i, m, n, total;
	int c;

	n = va_arg(o, unsigned int);
	m = 1073741824; /* (8 ^ 10) */
	a[0] = n / m;
	for (i = 1; i < 11; i++)
	{
		m /= 8;
		a[i] = (n / m) % 8;
	}
	for (i = 0, total = 0, c = 0; i < 11; i++)
	{
		total += a[i];
		if (total || i == 10)
		{
			_putchar('0' + a[i]);
			c++;
		}
	}
	return (c);
}
