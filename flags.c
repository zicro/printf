#include "main.h"

/**
 * get_flags - calculate actif flags
 * @format: Formatted string
 * @i: parameter
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	/*" - + 0 # ' ' " -> "1 2 4 8 16"*/
	int curr = *i + 1;
	int size = 0;

	if (format[curr] == 'l')
		size = S_LONG;
	else if (format[curr] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = curr - 1;
	else
		*i = curr;
	return (size);
}
