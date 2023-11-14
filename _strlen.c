#include"main.h"


/**
 * _strlen - Calculate the length of a null-terminated string
 * @str: The input string
 * Return: The length of the string
 */
int _strlen(const char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}
return (len);
}
