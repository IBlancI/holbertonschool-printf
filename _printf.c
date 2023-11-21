#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: format char string to check
 * Description: replica of the printf function of the standard library
 * Return: number of characters excluding the null byte
 */

int _printf(const char *format, ...)
{
	/* création de la variable ind essentiel à notre boucle*/
	int ind;
	/* création de la variable qui va contenir le nombre de caractère imprimer*/
	int strFormat_leng = 0;

	/* création de la variable qui va contenir notre liste d'arguments */
	va_list arguments_list;

	if (format == NULL || format[0] == '\0')
		return (-1);

	/*Remplissage de notre variable avec les arguments*/
	va_start(arguments_list, format); 

}
