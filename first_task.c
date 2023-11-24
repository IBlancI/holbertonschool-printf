#include <stdio.h>
#include <stdarg.h>
#include "main.h"


/**
 * print_char - Imprime un caractère.
 * @c: Le caractère à imprimer.
 * @count: Pointeur vers le compteur de caractères imprimés.
 */
static void print_char(char c, int *count)
{
	putchar(c);
	(*count)++;
}

/**
 * print_str - Imprime une chaîne de caractères.
 * @s: La chaîne de caractères à imprimer.
 * @count: Pointeur vers le compteur de caractères imprimés.
 */
static void print_str(char *s, int *count)
{
	while (*s != '\0')
	{
		putchar(*s);
		s++;
		(*count)++;
	}
}

/**
 * _printf - Simule la fonction printf en C.
 * @format: Chaîne de format.
 *
 * return : Le nombre de caractères imprimés (hors octet nul).
 */

int _printf1(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				print_str(va_arg(args, char *), &count);
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				count += 2;
			}
		}
		else
		{
			print_char(*format, &count);
		}

		format++;
	}

	va_end(args);

	return (count);
}
