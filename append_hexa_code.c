#include "main.h"

/**
 * append_hexa_code - Append ascci in hexadecimal code -> buffer
 * @buffer: Array of characters.
 * @i: Index -> start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	unsigned char code = (unsigned char)ascii_code;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[code / 16];
	buffer[i] = map_to[code % 16];

	return (3);
}
