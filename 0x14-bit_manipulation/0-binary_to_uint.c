#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int Decimal_num = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] == '0' || b[i] == '1')
		{
			Decimal_num = 2 * Decimal_num + (b[i] - '0');
			i++;
		}
		else
			return (0);
	}
	
	return (Decimal_num);
}
