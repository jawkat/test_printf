#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte),
 * or -1 on error
 */
int _printf(const char *format, ...)
{
	int char_count = 0; /* Initialize the character count */
	va_list args;       /* Declare a variable the variable arguments */

	va_start(args, format); /* Start processing the variable arguments */
	if (_format(format, args, &char_count) == -1)
	{
		va_end(args); /* End processing the variable arguments on error */
		return (-1);
	}
	va_end(args); /* End processing the variable arguments */

	return (char_count); /* Return the total number of characters printed */
}

