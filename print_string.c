#include "main.h"
/**
 * print_string - writes a string
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: width.
 * @precision: precision specification
 * @size: Size
 * Return: Characters
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			handle_left_padding(str, width, length, flags);
			return (width);
		}
		else
		{
			handle_right_padding(str, width, length, flags);
			return (width);
		}
	}

	write(1, str, length);
	return (length);
}

