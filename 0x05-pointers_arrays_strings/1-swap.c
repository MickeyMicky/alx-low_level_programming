#include "main.h"

/**
 * swap_int - function that swaps the values of two integers
 * @a: integer to be swapped
 * @b: integer to be swapped
 * Return: swapped integers
 */

void swap_int(int *a, int *b)
{
	int m;

	m = *a;
	*a = *b;
	*b = m;
}
