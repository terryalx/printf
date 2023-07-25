#include "main.h"

/**
 * write_num - Write a number using a bufffer
 * @ind: Index
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: precision - specifier
 * @length: length
 * @padd: Pading character
 * @extra_c: Extra characters
 * Return: Characters
 */

int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c)
{
	int i, start_padd = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--start_padd] = extra_c;
			return (write(1, &buffer[start_padd], i - start_padd) +
					write(1, &buffer[ind], length - (1 - start_padd)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}
