#include "main.h"

/**
 * get_bit - function that returns the value of a bit
 * at an index in a decimal number
 * @n: number to search
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	bit = (n >> index) & 1;

	return (bit);
}
