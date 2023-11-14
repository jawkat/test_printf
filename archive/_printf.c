#include "main.h"

/**
 * _printf - my printf function supporting %c, %s,%d
 * @format: The string
 * Return: number of caractere imprime
 */
int _printf(const char *format, ...)
{
	int char_count = 0; /* count nombre printed characters */

	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			switch (*(format + 1))
			{
				case 'c':
					print_char(va_arg(args, int), &char_count);
					break;
				case 's':
					{
						char *str = va_arg(args, char *);

					if (str)
						print_str(str, &char_count);
					else
						print_str("(null)", &char_count);
					}
					break;
				default:
					print_unsupported(*(format + 1), &char_count);
					break;
			}
			format += 2; /* Move to the next format specifier */
		}
		else
		{
			print_char(*format, &char_count);
			++format;
		}
	}
	va_end(args);
	return (char_count); /* Return the count of printed characters*/
}
