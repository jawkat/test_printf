include"main.h"
/**
 * my_printf - Custom printf function
 * @format: The format string
 * @...: Variable arguments
 *
 * Return: The total number of characters printed
 */
int my_printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			if (*(format + 1) == '%')
			{
				print_char('%', &char_count);
				format += 2;
			}
			else
			{
				switch (*(format + 1))
				{
				case 'c':
					print_char(va_arg(args, int), &char_count);
					break;
				case 's':
					print_str(va_arg(args, char *), &char_count);
					break;
				case 'd':
					print_int(va_arg(args, int), &char_count);
					break;
				default:
					print_unsupported(*(format + 1), &char_count);
					break;
				}
				format += 2;
			}
		}
		else
		{
			print_char(*format, &char_count);
			++format;
		}
	}
	va_end(args);
	return char_count;
}
