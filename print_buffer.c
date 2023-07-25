#include "main.h"

/**
 * print_buffer - write out the contents of buffer if any
 * @buffer: Array in buffer
 * @buff_ind: Index
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
