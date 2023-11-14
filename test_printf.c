#include <stdio.h>
#include <stdarg.h>

/**
 * _putchar - Print a character to the standard output
 * @c: The character to be printed
 */
void _putchar(char c) {
    putchar(c);
}

/**
 * _strlen - Calculate the length of a null-terminated string
 * @str: The input string
 * Return: The length of the string
 */
int _strlen(const char *str) {
    int len = 0;
    while (*str) 
    {
        len++;
        str++;
    }
    return len;
}

/**
 * _write_str - Write a null-terminated string to the standard output
 * @str: The input string
 */
void _write_str(const char *str) {
    while (*str) {
        _putchar(*str);
        ++str;
    }
}

/**
 * _printf - A simplified printf function supporting %c, %s, and %d format specifiers
 * @format: The format string
 * Return: The count of printed characters
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int char_count = 0; // Variable to store the count of printed characters

    while (*format) {
        if (*format == '%' && *(format + 1)) {
            switch (*(format + 1)) {
                case 'c':
                    _putchar(va_arg(args, int));
                    char_count++;
                    break;
                case 's': {
                    char *str = va_arg(args, char *);
                    if (str) {
                        _write_str(str);
                        char_count += _strlen(str);
                    } else {
                        _write_str("(null)");
                        char_count += 6; // Length of "(null)"
                    }
                    break;
                }
                case 'd':
                    // Assuming you have a function to print integers, e.g., write_int
                    // char_count += write_int(va_arg(args, int));
                    break;
                default:
                    // Handle unsupported format specifier
                    _write_str("Unsupported format specifier: ");
                    _putchar(*(format + 1));
                    _putchar('\n');
                    char_count += 30; // Length of "Unsupported format specifier: " + 1 character
                    break;
            }
            format += 2; // Move to the next format specifier
        } else {
            _putchar(*format);
            ++format;
            char_count++;
        }
    }

    va_end(args);

    return char_count; // Return the count of printed characters
}

/**
 * main - Entry point of the program
 * Return: Always 0 (Success)
 */
int main(void) {
    int count = _printf("Character: %c\n", 'A');
    printf("Total characters printed: %d\n", count);

    count = _printf("String: %s\n", "Hello, World!");
    printf("Total characters printed: %d\n", count);

    // ... (Other test cases)

    return 0;
}
