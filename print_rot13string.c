#include "main.h"

/**
 * print_rot13string - print a string in rot13.
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: width
 * @precision: precision - specification
 * @size: Size
 * Return: Characters
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char cp1;
	char *str;
	unsigned int a, b;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				cp1 = out[b];
				write(1, &cp1, 1);
				count++;
				break;
			}
		}
		if (!in[b])
		{
			cp1 = str[a];
			write(1, &cp1, 1);
			count++;
		}
	}
	return (count);
}
