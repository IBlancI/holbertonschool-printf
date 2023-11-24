#include "main.h"

/**
 *  * _printf - Function that produces output according to a format.
 *   * @format: Format character string to check
 *    * Description: Replica of the printf function of the standard library
 *     * Return: Number of characters printed excluding the null byte
 *      */
int _printf(const char *format, ...)
{
	/* Déclaration de la variable index essentiel à notre boucle for*/
	/* Variable strFormat_leng qui va compter le nombre de char dans format*/
	int index, strFormat_leng = 0;
	/* Variable arguments_list --> sert à stocker nos multiples arguments*/
	va_list arguments_list;

	/* Check si format est NULL ou si format est vide*/
	if (format == NULL || format[0] == '\0')
		return (-1);

	/* Initialisation de arguments_list --> attribution des arguments en value*/
	va_start(arguments_list, format);

	/* Boucle for qui va parcourir format*/
	for (index = 0; format[index] != '\0'; index++)
	{
		/* Si format[index] est différent de '%'*/
		/* Alors on print format[index] et on incrémente strFormat_leng*/
		if (format[index] != '%')
		{
			write(1, &format[index], 1);
			strFormat_leng++;
		}
		/* Sinon cela signife que format contient un format specifier*/
		/* On incrémente pour regarder le caractère qui suit le '%'*/
		else
		{
			index++;
			/* On appelle donc la fonction handle_format qui va gérer le specifier*/
			/* On lui passe en paramètre le format specifier et arguments_list*/
			/* On incrémente strFormat_leng du nombre de char retourné par la func*/
			strFormat_leng += handle_format(format[index], arguments_list);
		}
	}
	/* Clean up : on termine notre liste d'arguments*/
	va_end(arguments_list);
	/* On retourne le nombre total de caractères dans la format string*/
	return (strFormat_leng);
}
