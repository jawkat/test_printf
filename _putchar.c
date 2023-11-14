#include "main.h"

/**
 * _putchar - Print a character to standard output
 * @c: The character to print
 * @char_count: Pointer to the character count
 */
void _putchar(int c, int *char_count)
{
	if (write(1, &c, 1) == -1)
		return;

	(*char_count)++;
}
