#include "main.h"

/**
 * _printf - our printf function
 * @format: The string
 * @...: argument variable
 *
 * Return: count the number of characters printed
 */
int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;

	va_start(args, format);
	_format(format, args, &char_count);
	va_end(args);

	return (char_count);
}


