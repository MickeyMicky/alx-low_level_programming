#include "main.h"

/**
 * rev_string - function that reverses a string
 * @s: string
 * Return: void
 */

void rev_string(char *s)
{
	int i;
	int count = 0;
	char c =  s[0];

	while (s[count] != '\0')
	{
		count++;
	}
	for (i = 0 ; i < count ; i++)
	{
		count--;
		c = s[i];
		s[i] = s[count];
		s[count] = c;
	}
}
