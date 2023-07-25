#include "main.h"

/**
 * handle_write_char - writes out a string
 * @c: char type
 * @buffer: Buffer
 * @flags: active flags.
 *
 * @width: width.
 * @precision: precision
 * @size: Size -> specifier
 * Return: Number of characters printed.
 */

int handle_write_char(char c, char buffer[],
		int flags, int width,
		int precision, int size)
{
	int i = 0;

	UNUSED(precision);
	UNUSED(size);

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		return (write_with_width(buffer, flags, width));
	}

	return (write(1, &buffer[0], 1));
}
