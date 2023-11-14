#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>


void _putchar(int c, int *char_count);

void _format(const char *format, va_list args, int *char_count);

void print_str(char *str, int *char_count);

void print_int_recursive(int n, int *char_count);

void print_int(int n, int *char_count);

void _unsupported(char c, int *char_count);

int _printf(const char *format, ...);

#endif
