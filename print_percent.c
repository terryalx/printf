#include "main.h"

/**
 * print_percent - write % sign
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: width.
 * @precision: precision - specification
 * @size: Size
 * Return: Characters
 */

int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	
	return (write(1, "%%", 1));
}
