#include "main.h"
/**
 * handle_format - Handle the format specifier in the printf loop
 * @format: Format string
 * @list: Argument list
 * @buffer: Buffer array to handle print
 * @buff_ind: Index in the buffer
 * Return: Number of characters printed.
 */
int handle_format(const char *format, va_list list,
		char buffer[], int *buff_ind)
{
	int i, input_char = 0, output_char = 0;
	int flags, width, precision, size;

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[*buff_ind] = format[i];
			(*buff_ind)++;
			if (*buff_ind == BUFF_SIZE)
				print_buffer(buffer, buff_ind);
			output_char++;
		}
		else
		{
			print_buffer(buffer, buff_ind);
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
	return (output_char);
}

