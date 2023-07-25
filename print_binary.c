#include "main.h"

/**
 * print_binary - write -> print an unsigned number
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: width.
 * @precision: precision - specification
 * @size: size of specifier
 * Return: count
 */

int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int nb, mb, i, c_sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	nb = va_arg(types, unsigned int);
	mb = 2147483648; /* (2 ^ 31) */
	a[0] = nb / mb;
	for (i = 1; i < 32; i++)
	{
		mb /= 2;
		a[i] = (nb / mb) % 2;
	}
	for (i = 0, c_sum = 0, count = 0; i < 32; i++)
	{
		c_sum += a[i];
		if (c_sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
