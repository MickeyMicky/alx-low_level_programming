#include "main.h"

/**
 * _memcpy -  a function that copies memory area.
 * @dest: memory area
 * @src: memory area
 * @n: bytes copied
 *
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i;
	int num = n;

	for (i = 0 ; i < num ; i++)
	{
		dest[i] = src[i];
		n--;
	}
	return (dest);
}
