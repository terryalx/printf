#include "main.h"

/**
 * print_int - prints int
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: width.
 * @precision: precision specification
 * @size: size specifier
 * Return: characters
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int l_n = va_arg(types, long int);
	unsigned long int l_num;

	l_n = convert_size_number(l_n, size);

	if (l_n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	l_num = (unsigned long int)l_n;

	if (l_n < 0)
	{
		l_num = (unsigned long int)((-1) * l_n);
		is_negative = 1;
	}

	while (l_num > 0)
	{
		buffer[i--] = (l_num % 10) + '0';
		l_num /= 10;
	}

	i++;

	return (write_number(is_negative, i,
	buffer, flags, width, precision, size));
}
