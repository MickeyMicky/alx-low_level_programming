#include "main.h"

/**
 * flip_bits - function that counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int current = 0;
	unsigned long int result = n ^ m;

	while (result)
	{
		current += result & 1;
		result >>= 1;
	}

	return (current);
}
