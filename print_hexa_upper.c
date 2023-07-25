#include "main.h"

/**
 * print_hexa_upper - print an unsigned number - hexadecimal
 * @types: arguments
 * @buffer: Buffer array
 * @flags: active flags
 * @width: width
 * @precision: precision - specification
 * @size: Size
 * Return: characters
 */

int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}
