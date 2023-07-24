#include "main.h"

/**
 * puts2 - function that prints every other character of a string,
 * starting with the first character
 * @str: input
 * Return: void
 */

void puts2(char *str)
{
	int count = 0;
	int i = 0;
	char *c = str;
	int j;

	while (*c != '\0')
	{
		c++;
		count++;
	}
	i = count - 1;
	for (j = 0 ; j <= i ; j++)
	{
		if (j % 2 == 0)
		{
			_putchar(str[j]);
		}
	}
	_putchar('\n');
}
