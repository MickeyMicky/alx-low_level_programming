#include "main.h"

/**
 * _strchr - a function that locates a character in a string.
 * @s: string
 * @c: string
 *
 * Return: character or null
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i =  0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	if (*s == c)
		return (s);
	return (0);
}