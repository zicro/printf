#include "main.h"

/**
 * put_rot13 - string printer in rot13 mode.
 * @R: string to be printed
 *
 * Return: printed characters count
 */
int put_rot13(va_list R)
{
	char *ch;
	unsigned int i, j;
	int c = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	ch = va_arg(R, char *);
	if (ch == NULL)
		ch = "(ahyy)";
	for (i = 0; ch[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == ch[i])
			{
				_putchar(output[j]);
				c++;
				break;
			}
		}
		if (!input[j])
		{
			_putchar(ch[i]);
			c++;
		}
	}
	return (c);
}
