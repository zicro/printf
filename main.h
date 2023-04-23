#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct put - structure for types printing
 * @type: type to print
 * @func: function to be printed
 */
typedef struct put
{
	char *type;
	int (*func)(va_list);
} puts_list;

int _putchar(char c);
int _printf(const char *format, ...);
int put_char(va_list c);
int put_string(va_list s);
int put_integer(va_list i);
int put_decimal(va_list d);
int put_unsigned(va_list u);
int put_binary(va_list b);
int put_octal(va_list o);
int put_lower_hex(va_list x);
int put_upper_hex(va_list X);
int put_address(va_list p);
int put_unprintable(va_list S);
int put_reverse(va_list r);
int put_rot13(va_list R);

#endif
