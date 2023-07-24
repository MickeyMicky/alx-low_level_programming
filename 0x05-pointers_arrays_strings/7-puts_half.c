#include "main.h"

/**
 * puts_half - function that prints half of a string
 * if odd len, n = (length_of_the_string - 1) / 2
 * @str: input
 * Return: half of input
 */

void puts_half(char *str)
{
	int i, half, count;

	count = 0;

	for (i = 0; str[i] != '\0'; i++)
		count++;

	half = (count / 2);

	if ((count % 2) == 1)
		half = ((count + 1) / 2);

	for (i = half ; str[i] != '\0' ; i++)
		_putchar(str[i]);
	_putchar('\n');
}

