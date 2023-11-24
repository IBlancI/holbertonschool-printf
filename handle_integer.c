#include "main.h"

/**
 * * handle_integer - Handles the 'd' and 'i' format specifiers (integer)
 * * @arguments_list: Variable containing the arguments of variadic function
 * * Description: This function prints an integer
 * * Return: Number of integers printed
 * */
int handle_integer(va_list arguments_list)
{
	/* Déclaration de la variable len_integer - stock le nb de printed int*/
	int len_integer;
	/* Variable integer avec pour valeur le prochain argument en paramètre*/
	int integer = va_arg(arguments_list, int);
	/* Variable buffer qui va stocker la conversion l'integer en string*/
	char buffer[50];

	/* On appelle la fonction sprintf qui va convertir l'integer en string*/
	/* On stock le résultat dans buffer*/
	sprintf(buffer, "%d", integer);

	/* On calcule le nombre de char dans buffer*/
	/* On attribue ce nombre à len_integer*/
	len_integer = strlen(buffer);

	/* On print buffer(= conversion de l'int en string) dans stdout*/
	write(1, buffer, len_integer);

	/* On retourne le nombre de caractères printed/la longueur de buffer*/
	return (len_integer);
}
