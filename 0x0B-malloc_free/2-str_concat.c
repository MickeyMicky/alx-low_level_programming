#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - function that concatenates two strings
 * @s1: string
 * @s2: string
 *
 * Return: s1 and s2 or NULL
 */

char *str_concat(char *s1, char *s2)
{
	char *concat;
	size_t len_1, len_2, total_len;

	if (s1 == NULL)
		s1 = " ";

	if (s2 == NULL)
		s2 = " ";

	len_1 = strlen(s1);
	len_2 = strlen(s2);
	total_len = len_1 + len_2 + 1;

	concat = malloc(sizeof(char) * total_len);
	if (concat == NULL)
		return (NULL);
	strcpy(concat, s1);
	strcat(concat,  s2);

	return (concat);
}
