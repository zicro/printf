#include "main.h"
/**
 * put_decimal - function print decimal
 * @d: input
 * Return: digit count that was printed
 */
int put_decimal(va_list d)
{
	int a[10];
	int l, h, o, total, c;

	o = va_arg(d, int);
	c = 0;
	l = 1000000000;
	a[0] = o / l;
	for (h = 1; h < 10; h++)
	{
		l /= 10;
		a[h] = (o / l) % 10;
	}
	if (o < 0)
	{
		_putchar('-');
		c++;
		for (h = 0; h < 10; h++)
			a[h] *= -1;
	}
	for (h = 0, total = 0; h < 10; h++)
	{
		total += a[h];
		if (total != 0 || h == 9)
		{
			_putchar('0' + a[h]);
			c++;
		}
	}
	return (c);
}
