#include "main.h"

/**
 * _printf -> Printf function
 *
 * @format: format
 *
 * Return: Printed characters
 */

int _printf(const char *format, ...)
{
	int output_char = 0;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	output_char = handle_format(format, list, buffer, &buff_ind);

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (output_char);
}
