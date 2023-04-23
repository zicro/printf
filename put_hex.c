#include "main.h"

/**
 * put_hex - prints in hexidecimal way the unsigned int
 * @num: the unsigned int to be printed
 * @_case: define the printing case (0 for lower, 1 for UPPER)
 *
 * Return: printed count numbers
 */
int put_hex(unsigned int num, unsigned int _case)
{
	unsigned int a[8];
	unsigned int i, m, total;
	char delta;
	int c;

	m = 268435456; /* (16 ^ 7) */
	if (_case)
		delta = 'A' - ':';
	else
		delta = 'a' - ':';
	a[0] = num / m;
	for (i = 1; i < 8; i++)
	{
		m /= 16;
		a[i] = (num / m) % 16;
	}
	for (i = 0, total = 0, c = 0; i < 8; i++)
	{
		total += a[i];
		if (total || i == 7)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + delta + a[i]);
			c++;
		}
	}
	return (c);
}
/**
 * put_lower_hex - print an unsigned integer to lowercase hexadecimal
 * @x: unsigned int to be printed
 *
 * Return: printed count digits
 */
int put_lower_hex(va_list x)
{
	return (put_hex(va_arg(x, unsigned int), 0));
}

/**
 * put_upper_hex - print an unsigned integer to UPPERCASE hexadecimal
 * @X: unsigned int to print
 *
 * Return: printed count digits
 */
int put_upper_hex(va_list X)
{
	return (put_hex(va_arg(X, unsigned int), 1));
}

/**
 * hex_put - prints ascii value for chars in uppercase
 * @c: char to be printed
 *
 * Return: printed char counts (that is exactly 2)
 */
static int hex_put(char c)
{
	int cnt;
	char delta = 'A' - ':';
	char d[2];

	d[0] = c / 16;
	d[1] = c % 16;
	for (cnt = 0; cnt < 2; cnt++)
	{
		if (d[cnt] >= 10)
			_putchar('0' + delta + d[cnt]);
		else
			_putchar('0' + d[cnt]);
	}
	return (cnt);
}

/**
 * put_unprintable - prints a non-printable ascii chars
 * @S: string to be printed
 *
 * Return: printed number of chars
 */
int put_unprintable(va_list S)
{
	unsigned int i;
	int c = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			c += 2;
			c += hex_put(str[i]);
		}
		else
		{
			_putchar(str[i]);
			c++;
		}
	}
	return (c);
}
