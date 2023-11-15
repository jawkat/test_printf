#include "main.h"

/**
 * _format - Parse the format and call appropriate print functions
 * @format: The format string
 * @args: Variable arguments
 * @char_count: Pointer to the character count
 * Return: On success, 0 is returned. On error, -1 is returned.
 */
int _format(const char *format, va_list args, int *char_count)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (*(format + 1) == '%')
			{
				_putchar('%', char_count);
				format += 2;
				continue;
			}
			if (*(format + 1) == 'c')
				_putchar(va_arg(args, int), char_count);
			else if (*(format + 1) == 's')
				print_str(va_arg(args, char *), char_count);
			else if (*(format + 1) == 'd' || *(format + 1) == 'i')
				print_int(va_arg(args, int), char_count);
			else if (*(format + 1) == 'b')
				print_binary(va_arg(args, unsigned int), char_count);
			else
			{
				_unsupported(*(format + 1), char_count);
			}
			if (*char_count == -1)  /* Check for error in _putchar */
				return (-1);
			format += 2;  /* Move to the next format specifier */
		}
		else
		{
			_putchar(*format, char_count);
			if (*char_count == -1)  /* Check for error in _putchar */
				return (-1);
			++format;  /* Move to the next character in the format string */
		}
	}

	return (0);  /* Return 0 on success */
}

/**
 * _unsupported - Handle unsupported format specifier
 * @c: The unsupported format specifier
 * @char_count: Pointer to the character count
 */
void _unsupported(char c, int *char_count)
{
	_putchar('%', char_count);
	_putchar(c, char_count);
}

