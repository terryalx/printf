#include "main.h"

/**
 * is_printable - check if a c is printable
 * @c: Character to check
 * Return: 1 -> printable, else 0
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
