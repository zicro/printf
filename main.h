#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

#define UNUSED(x)(void)(x)

/*FLAGS*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*size*/
#define S_LONG 2
#define S_SHORT 1

/**
 * struct put - structure for types printing
 * @t: type to print
 * @f: function to be printed
 */
typedef struct put
{
	char *type;
	int (*func)(va_list);
} puts_list;

int get_flags(const char *format, int *i);
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
