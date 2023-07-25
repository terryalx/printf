#include "main.h"

/**
 * print_unsigned - print an unsigned number
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: width
 * @precision: precision - specification
 * @size: Size
 * Return: Character
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int l_num = va_arg(types, unsigned long int);

	l_num = convert_size_unsgnd(l_num, size);

	if (l_num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (l_num > 0)
	{
		buffer[i--] = (l_num % 10) + '0';
		l_num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
