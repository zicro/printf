#include "main.h"

/**
 * put_binary - get the unsigned int into a binary format
 * @b: unsigned int to be printed
 *
 * Return: count of printed digits
 */
int put_binary(va_list b)
{
	unsigned int n, m, i, total;
	unsigned int a[32];
	int c;

	n = va_arg(b, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, total = 0, c = 0; i < 32; i++)
	{
		total += a[i];
		if (total || i == 31)
		{
			_putchar('0' + a[i]);
			c++;
		}
	}
	return (c);
}
