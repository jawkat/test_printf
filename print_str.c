#include "main.h"

/**
 * print_str - Print a string to standard output
 * @str: The string to print
 * @char_count: Pointer to the character count
 */
void print_str(char *str, int *char_count)
{
	if (!str)
	{
		print_str("(null)", char_count);
		return;
	}

	while (*str)
		_putchar(*str++, char_count);
}
