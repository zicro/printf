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
