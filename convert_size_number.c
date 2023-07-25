#include "main.h"

/**
 * convert_size_number -> specific size
 * @num: The number
 * @size: Number type
 * Return: num
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}
