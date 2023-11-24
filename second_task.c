#include "main.h"
/*
 * Fonction _printf qui imite partiellement la fonction printf du langage C
 * Elle prend un format et une liste variable d'arguments
 */
int main(void)
{
return 0;
}

int _printf(const char *format, ...) 
{
	int count = 0; /* Variable pour suivre le nombre de caractères imprimés */
	va_list args; /* Déclaration de la liste d'arguments variable */
	va_start (args, format); /* Initialisation de la liste d'arguments variable avec le format */

    while (*format != '\0')
	{
		/* Gestion des spécificateurs de conversion */
		if (*format == 'd' || *format == 'i') 
		{
                	/* Gérer %d et %i : entier signé */
                	int num = va_arg(args, int);
			printf("%d", num);
			count++;
		}
		else if (*format == 'c')
		{
			/* Gérer %c : caractère */
			char ch = va_arg(args, int); /* Va_arg pour un caractère doit retourner int */
			putchar(ch);
			count++;
		}
		else 
		{
            	/* Caractère ordinaire, l'imprimer */
            	putchar(*format);
            	count++;
        	}
	}

    format++;  /* Passer au caractère suivant dans la chaîne de format */
    va_end(args);  /* Nettoyer la liste d'arguments variable */

    return count;
}
