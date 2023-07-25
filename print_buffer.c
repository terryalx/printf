#include "main.h"
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of characters
 * @buff_ind: Index of nect char
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}