#include "main.h"

/**
 * write_number - prints string
 * @is_negative: arguments
 * @ind: type
 * @buffer: Buffer
 * @flags: active flags
 * @width: width.
 * @precision: precision - specifier
 * @size: Size
 * Return: Character
 */

int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}
