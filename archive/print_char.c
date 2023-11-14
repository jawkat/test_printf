#include "main.h"

/**
 * print_char - Print a single character and update char_count
 * @c: The character to print
 * @char_count: Pointer to the count of printed characters
 */
void print_char(int c, int *char_count)
{
	*char_count += write(1, &c, 1);
}

