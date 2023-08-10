#include "main.h"
#include <string.h>

/**
 * string_nconcat - function that concatenates two strings.
 * @s1: string
 * @s2: string
 * @n: number
 *
 * Return: concatenated two strings else null
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *conc;
	unsigned int s1_len, s2_len, i, j;

	if (s1 == NULL)
		s1 = " ";
	if (s2 == NULL)
		s2 = " ";

	/*s1_len = strlen(s1);*/
	/*s2_len = strlen(s2);*/

	s1_len = 0;
	s2_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	while (s2 && s2[s2_len])
		s2_len++;

	if (n < s2_len)
		conc = malloc(sizeof(char) * (s1_len + n + 1));
	else
		conc = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (conc == NULL)
		return (NULL);

	i = 0;
	j = 0;

	while (i < s1_len)
	{
		conc[i] = s1[i];
		i++;
	}

	while (n < s2_len && i < (s1_len + n))
		conc[i++] = s2[j++];

	while (n >= s2_len && i < (s1_len + s2_len))
		conc[i++] = s2[j++];

	conc[i] = '\0';

	return (conc);
}
