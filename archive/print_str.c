#include "main.h"

/**
 * print_char - Write a character to stdout and update char_count
 * @c: The character to write
 * @char_count: Pointer to the count of printed characters
 *
 * Return: On success, returns the number of characters written (1).
 * On error, returns -1 and sets errno appropriately.
 */
int print_char(int c, int *char_count)
{
	return write(1, &c, 1) == 1 ? ++(*char_count) : -1;
}

/**
 * print_str - Print a string and update char_count
 * @str: The string to print
 * @char_count: Pointer to the count of printed characters
 */
 
void print_str(char *str, int *char_count)
{
	if (str)
	{
		while (*str)
		{
			print_char(*str, char_count);
			str++;
		}
	}
}

