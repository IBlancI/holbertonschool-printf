#include "main.h"

/**
 * * handle_format - Handles the format specifier
 * * @format: The format specifier character
 * * @arguments_list: Variable containing the arguments of variadic function
 * * Description: Checks the format specifier and calls the right function
 * * Return: Number of characters printed
 * */
int handle_format(char format, va_list arguments_list)
{
	/* Variable strFormat_leng qui va compter le nombre de char dans format*/
	int strFormat_leng = 0;

	if (format == 'c')
	{
		strFormat_leng = strFormat_leng + handle_character(arguments_list);
	}
	else if (format == 's')
	{
		strFormat_leng = strFormat_leng + handle_string(arguments_list);
	}
	else if (format == '%')
	{
		strFormat_leng = strFormat_leng + handle_percent();
	}
	else if (format == 'd' || format == 'i')
	{
		strFormat_leng = strFormat_leng + handle_integer(arguments_list);
	}
	else if (format == 'p')
	{
		strFormat_leng = strFormat_leng + handle_integer(arguments_list);
	}

	else
	{
		write(1, "%", 1);
		write(1, &format, 1);
		strFormat_leng = strFormat_leng + 2;
	}

	return (strFormat_leng);
}
