#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/**
 * print_char - Print a character to standard output
 * @c: The character to print
 * @char_count: Pointer to the character count
 */
void print_char(int c, int *char_count)
{
	if (write(1, &c, 1) == -1)
		return;  // Handle write error here

	(*char_count)++;
}

/**
 * print_str - Print a string to standard output
 * @str: The string to print
 * @char_count: Pointer to the character count
 */
void print_str(char *str, int *char_count)
{
	if (!str)
	{
		print_str("(null)", char_count);
		return;
	}

	while (*str)
		print_char(*str++, char_count);
}

/**
 * print_int - Print a non-negative integer to standard output
 * @n: The integer to print
 * @char_count: Pointer to the character count
 */
void print_int(int n, int *char_count)
{
	// Custom implementation to print a non-negative integer
	// This implementation may not cover all cases
	// Handle negative numbers, zero, etc., based on your needs

	int tmp = n;
	int digits = 0;

	// Count the number of digits
	do
	{
		digits++;
		tmp /= 10;
	} while (tmp != 0);

	/* Convert and print each digit */
	for (int i = digits - 1; i >= 0; i--)
	{
		char digit = '0' + (n / 1) % 10;  // Simplified power of 10
		print_char(digit, char_count);
	}
}

/**
 * print_unsupported - Handle unsupported format specifier
 * @c: The unsupported format specifier
 * @char_count: Pointer to the character count
 */
void print_unsupported(char c, int *char_count)
{
	print_char('%', char_count);
	print_char(c, char_count);
}

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

int main(void)
{
	char *str = "world";
	char *null_str = NULL;

	my_printf("Hello, %s! This is a number: %d\n", str, 42);
	my_printf("This is a null string: %s\n", null_str);

	return 0;
}
