#include"main.h"


/**
 * print_unsupported - Print an unsupported specifier message
 * @specifier: The unsupported specifier
 * @char_count: Pointer to the count of printed characters
 */
void print_unsupported(char specifier, int *char_count)
{
	print_str("Unsupported format specifier: ", char_count);
	_putchar(specifier);
	_putchar('\n');
	(*char_count) += 31; /* Length "Unsupported specifier: " + 1 character */
}

