#include <stdio.h>
#include <stdarg.h>

// Fonction _printf qui imite partiellement la fonction printf du langage C
// Elle prend un format et une liste variable d'arguments
int _printf(const char *format, ...) {
    va_list args; // Déclaration de la liste d'arguments variable
    va_start(args, format); // Initialisation de la liste d'arguments variable avec le format

    int count = 0;  // Variable pour suivre le nombre de caractères imprimés

    while (*format != '\0') {
        if (*format == '%') {
           		 // Gestion des spécificateurs de conversion
            format++;  // Passer au caractère après '%'

            if (*format == 'c') {
                // Gérer %c : caractère
                char c = va_arg(args, int);  // Le char est promu en int dans les arguments variables
                putchar(c);
                count++;
            } else if (*format == 's') {
                // Gérer %s : chaîne de caractères
                char *s = va_arg(args, char *);
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*format == '%') {
                // Gérer %% : signe pourcentage
                putchar('%');
                count++;
            } else {
                // Spécificateur de conversion non pris en charge, ignorer
                putchar('%');
                putchar(*format);
                count += 2;
            }
        } else {
            // Caractère ordinaire, l'imprimer
            putchar(*format);
            count++;
        }

        format++;  // Passer au caractère suivant dans la chaîne de format
    }

    va_end(args);  // Nettoyer la liste d'arguments variable

    return count;
}