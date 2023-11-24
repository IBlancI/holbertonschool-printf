#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...) {
	int count = 0; /* Variable pour suivre le nombre de caractères imprimés */
	va_list args; /* Déclaration de la liste d'arguments variable */
	va_start(args, format); /* Initialisation de la liste d'arguments variable avec le format */

	while (*format != '\0') {
		/* Gestion des spécificateurs de conversion */
		if (*format == 'd' || *format == 'i') {
			/* Gérer %d et %i : entier signé */
			int num = va_arg(args, int);
			/* Utilisation de putchar pour imprimer un seul caractère à la fois */
			putchar(num + '0'); /* Convertit l'entier en caractère et l'imprime */
			count++;
		} else if (*format == 'c') {
			/* Gérer %c : caractère */
			char ch = va_arg(args, int); /* Va_arg pour un caractère doit retourner int */
			/* Utilisation de putchar pour imprimer un seul caractère à la fois */
			putchar(ch);
			count++;
		} else {
			/* Caractère ordinaire, l'imprimer */
			/* Utilisation de putchar pour imprimer un seul caractère à la fois */
			putchar(*format);
			count++;
		}

		format++; /* Passer au caractère suivant dans la chaîne de format */
	}

	va_end(args); /* Nettoyer la liste d'arguments variable */

	return count;
}

int main(void) {
	/* Utilisation de _printf avec putchar pour l'impression */
	_printf("Hello, %c! This is a %d example.\n", 'W', 42);

	return 0;
}

