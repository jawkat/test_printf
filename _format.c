#include "main.h"


/**
 * _format - Parse the format and call appropriate print functions
 * @format: The format string
 * @args: Variable arguments
 * @char_count: Pointer to the character count
 */
void _format(const char *format, va_list args, int *char_count)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (*(format + 1) == '%')
			{
				_putchar('%', char_count);
				format += 2;
			}
			else
			{
				switch (*(format + 1))
				{
				case 'c':
					_putchar(va_arg(args, int), char_count);
					break;
				case 's':
					print_str(va_arg(args, char *), char_count);
					break;
				case 'd':
				case 'i':
					print_int(va_arg(args, int), char_count);
					break;
				default:
					_unsupported(*(format + 1), char_count);
					break;
				}
				format += 2;
			}
		}
		else
		{
			_putchar(*format, char_count);
			++format;
		}
	}
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

