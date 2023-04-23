#include "main.h"

/**
 * _pow - involves raising a number to a certain power
 * @b: the base number
 * @exp: the exponent number
 *
 * Return: the power of the number
 */
static unsigned long _pow(unsigned int b, unsigned int exp)
{
	unsigned int i;
	unsigned long val = b;

	for (i = 1; i < exp; i++)
	{
		val *= b;
	}
	return (val);
}

/**
 * put_address - prints the number address
 * @p: address to be printed
 *
 * Return: the count of printed characters
 */
int put_address(va_list p)
{
	int c = 0;
	unsigned int a[16];
	unsigned int i, total;
	unsigned long n, m;
	char *ch = "(nil)";

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (i = 0; ch[i]; i++)
		{
			_putchar(ch[i]);
			c++;
		}
		return (c);
	}
	_putchar('0');
	_putchar('x');
	c = 2;
	m = _pow(16, 15); /* 16 ^ 15 */
	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, total = 0; i < 16; i++)
	{
		total += a[i];
		if (total || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			c++;
		}
	}
	return (c);
}
