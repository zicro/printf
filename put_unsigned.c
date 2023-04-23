#include "main.h"

/**
 * put_unsigned - get the unsigned int into a decimal format
 * @u: unsigned int to be printed
 *
 * Return: count of printed digits
 */
int put_unsigned(va_list u)
{
	unsigned int a[10];
	unsigned int i, m, n, total;
	int c;

	n = va_arg(u, unsigned int);
	m = 1000000000; /* (10 ^ 9) */
	a[0] = n / m;
	for (i = 1; i < 10; i++)
	{
		m /= 10;
		a[i] = (n / m) % 10;
	}
	for (i = 0, total = 0, c = 0; i < 10; i++)
	{
		total += a[i];
		if (total || i == 9)
		{
			_putchar('0' + a[i]);
			c++;
		}
	}
	return (c);
}
