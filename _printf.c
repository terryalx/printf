#include "main.h"

/**
 * _printf -> Printf function
 * @format: format
 * Return: Printed characters
 */

int _printf(const char *format, ...)
{
	int i;
	int input_char = 0;
	int output_char = 0;
	int flags, width, precision, size, buff_ind = 0;

	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			output_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			input_char = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (input_char == -1)
				return (-1);
			output_char += input_char;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (output_char);
}
