#include "main.h"

/**
 * * handle_string - Handles the 's' format specifier (string)
 * * @arguments_list: Variable containing the arguments of variadic function
 * * Description: This function prints a string
 * * Return: Number of characters printed
 * */
int handle_string(va_list arguments_list)
{
	char *string = va_arg(arguments_list, char*);
	int len_string;

	if (string == NULL)
		string = "(null)";

	len_string = strlen(string);

	write(1, string, len_string);

	return (len_string);
}
