#include "main.h"

/**
 * handle_right_padding - Write right padding
 * @str: String to write
 * @width: Width of the field
 * @length: Length of the string
 * @flags: Active flags
 */
void handle_right_padding(char *str, int width, int length, int flags)
{
	int i;

	if (flags & F_MINUS)
	{
		write(1, str, length);
		for (i = width - length; i > 0; i--)
			write(1, " ", 1);
	}
	else
	{
		for (i = width - length; i > 0; i--)
			write(1, " ", 1);
		write(1, str, length);
	}
}

