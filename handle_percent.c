#include "main.h"

/**
 * * handle_percent - Handles the '%%' format specifier (double percent)
 * * @void: Function doesn't take any arguments
 * * Description: This function prints a percent
 * * Return: Number of characters printed
 * */
int handle_percent(void)
{
	write(1, "%", 1);
	return (1);
}
