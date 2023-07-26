#include "main.h"

/**
 * get_flags - gets active flags
 *
 * @format: Formatted string
 *
 * @i: parameter
 *
 * Return: flags
 */

int get_flags(const char *format, int *i)
{
	int p;
	int current_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0', '!', '*'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (p = 0; FLAGS_CH[p] != '\0'; p++)
			if (format[current_i] == FLAGS_CH[p])
			{
				flags |= FLAGS_ARR[p];
				break;
			}

		if (FLAGS_CH[p] == 0)
			break;
	}

	*i = current_i - 1;

	return (flags);
}
