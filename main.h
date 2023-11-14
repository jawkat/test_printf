#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include<stdarg.h>

int _putchar(char c);
void _write_str(const char *str);
void print_char(int c, int *char_count);
int _strlen(const char *str);
void print_str(char *str, int *char_count);
void print_unsupported(char specifier, int *char_count);
int _printf(const char *format, ...);

#endif
