#include "main.h"

/**
 * write_with_width - Write the buffer with specified width and flags
 * @buffer: Buffer
 * @flags: active flags
 * @width: width
 * Return: Number of characters printed.
 */

int write_with_width(char buffer[], int flags, int width)
{
	int i;
	char padd = (flags & F_ZERO) && !(flags & F_MINUS) ? '0' : ' ';

	buffer[BUFF_SIZE - 1] = '\0';
	for (i = 0; i < width - 1; i++)
		buffer[BUFF_SIZE - i - 2] = padd;

	if (flags & F_MINUS)
		return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
	else
		return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
				write(1, &buffer[0], 1));
}

