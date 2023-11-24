#include "main.h"

/**
 * *  handle_pointer - Handles the 'p' format specifier (pointer)
 * * @arguments_list: Variable containing the arguments of variadic function
 * * Description: Function that print a pointer
 * * Return: Number of characters printed
 * */
int handle_pointer(va_list arguments_list)
{
	int num;

	void *ptr = va_arg(arguments_list, void *);

	char *buffer = malloc(20);

	if (buffer == NULL)
	{
		return (-1);
	}

	num = sprintf(buffer, "%p", ptr);

	write(1, buffer, num);
	free(buffer);

	return (num);
}
