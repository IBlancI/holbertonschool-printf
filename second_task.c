#include "main.h"
#include <stdarg.h>

/**
 * _printf - Simulates the printf function in C.
 * @format: Format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int count = 0; /* Variable to track the number of printed characters */
	va_list args; /* Declaration of the variable argument list */

	va_start(args, format);
		/* Initialization of the variable argument list with the format */

	while (*format != '\0')
	{
		/* Handling conversion specifiers */
		if (*format == 'd' || *format == 'i')
		{
			/* Handling %d and %i: signed integer */
			int num = va_arg(args, int);

			putchar(num + '0'); /* Convert the integer to a character and print */
			count++;
		}
		else if (*format == 'c')
		{
			/* Handling %c: character */
			char ch = va_arg(args, int); /* Va_arg for a character should return int */

			putchar(ch);
			count++;
		}
		else
		{
			/* Ordinary character, print it */
			putchar(*format);
			count++;
		}

		format++; /* Move to the next character in the format string */
	}

	va_end(args); /* Clean up the variable argument list */

	return (count);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	return (0);
}

