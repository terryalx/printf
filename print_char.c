#include "main.h"

/**
 * print_char - print a character
 * @types: arguments
 * @buffer: Buffer of array
 * @flags: active flags
 * @width: Width
 * @precision: precision - specification
 * @size: size
 * Return: all characters
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
