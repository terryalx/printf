#include "main.h"

/**
 * print_hexadecimal - unsigned number in hexadecimal
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: width
 * @precision: precision specification
 * @size: size
 * Return: Characters
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
	flags, 'x', width, precision, size));
}
