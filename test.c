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

/**
 * print_int - Print an integer and update char_count
 * @n: The integer to print
 * @char_count: Pointer to the count of printed characters
 */
void print_int(int n, int *char_count)
{
    /* Assuming you have a function write_int that writes an integer */
    *char_count += write_int(n);
}

/**
 * _printf - My printf function supporting %c, %s, and %d
 * @format: The string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int char_count = 0; /* Count of printed characters */
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
            case 'd':
                print_int(va_arg(args, int), &char_count);
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
    return char_count; /* Return the count of printed characters */
}

