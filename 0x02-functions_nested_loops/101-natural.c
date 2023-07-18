#include <stdio.h>

/**
 * main - Program that lists all the natural numbers
 * below 1024 (excluded) that are multiples of 3 or 5.
 *
 * Return: Always 0 (sucess)
 */

int main(void)
{
	int i, j = 0;

	for (i = 0; i < 1024; i++)
	{
		if ((i % 3) == 0 || (i % 5) == 0)
			j += i;
	}

	printf("%d\n", j);

	return (0);
}
