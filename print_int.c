#include <stdio.h>

void _putchar(char c, int *char_count)
{
    if (write(1, &c, 1) == -1)
        return;

    (*char_count)++;
}

void print_binary(unsigned int n, int *char_count, char *binary)
{
    int i;
    int digit;
    int _zeros = 1;  /* zeros */

    for (i = 31; i >= 0; i--)
    {
        digit = (n >> i) & 1;

        if (digit || !_zeros)
        {
            _putchar(digit + '0', char_count);
            _zeros = 0;  /* no longer used */
            *binary = digit + '0';
            binary++;
        }
    }

    // If the integer was 0, print a single 0
    if (_zeros)
    {
        _putchar('0', char_count);
        *binary = '0';
    }
    else
    {
        *binary = '\0';  // Null-terminate the string
    }
}

int binaryToDecimal(const char *binary)
{
    int result = 0;
    while (*binary != '\0')
    {
        result = result * 2 + (*binary - '0');
        binary++;
    }
    return result;
}

int binaryToOctal(const char *binary)
{
    int result = 0;
    int weight = 1;
    int digit;
    while (*binary != '\0')
    {
        digit = *binary - '0';
        result = result * 2 + digit;
        weight *= 2;
        binary++;
    }
    return result;
}

int binaryToHexadecimal(const char *binary)
{
    int result = 0;
    int weight = 1;
    int digit;
    while (*binary != '\0')
    {
        digit = *binary - '0';
        result = result * 2 + digit;
        weight *= 2;
        binary++;
    }
    return result;
}

int main(void)
{
    int char_count = 0;
    char binary_representation[32];  // Assuming a 32-bit integer

    unsigned int number = 200;  // Replace with your desired number

    printf("Binary representation of %u: ", number);
    print_binary(number, &char_count, binary_representation);
    printf("\n");

    printf("Decimal: %d\n", binaryToDecimal(binary_representation));
    printf("Octal: %o\n", binaryToOctal(binary_representation));
    printf("Hexadecimal: %X\n", binaryToHexadecimal(binary_representation));

    return 0;
}
