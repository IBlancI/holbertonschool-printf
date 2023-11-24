#include "main.h"

/**
 * * handle_character - Handles the 'c' format specifier (character)
 * * @arguments_list: Variable containing the arguments of variadic function
 * * Description: This function prints a character
 * * Return: Number of characters printed
 * */
int handle_character(va_list arguments_list)
{
	/* Variable c qui est initialisé avec le prochain argument en paramètre*/
	char c = va_arg(arguments_list, int);

	/* On print le char c dans stdout*/
	write(1, &c, 1);

	/* On retourne le nombre de caractères printed*/
	/* Ça sera toujours 1 car on print un seul char*/
	return (1);
}
