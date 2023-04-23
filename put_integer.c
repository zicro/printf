#include "main.h"
/**
 * put_integer - prints a integer value
 * @i: input
 *
 * Return: digits count that was printed
 */
int put_integer(va_list i)
{
	int a[10];
	int h, l, o, total, c;

	o = va_arg(i, int);
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
