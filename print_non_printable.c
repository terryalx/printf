#include "main.h"

/**
 * print_non_printable - ascii codes -> hex
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: width
 * @precision: Precision - specification
 * @size: Size
 * Return: Characters
 */

int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = 0;
	int cuurent_nm = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + cuurent_nm] = str[i];
		else
			cuurent_nm += append_hexa_code(str[i], buffer, i + cuurent_nm);

		i++;
	}

	buffer[i + cuurent_nm] = '\0';

	return (write(1, buffer, i + cuurent_nm));
}
