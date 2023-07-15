#include <stdio.h>
/**
 * main - main func
 *
 * Return: always 0
 */

int main(void)
{
	int i = '0';
	int j = '0';

	for (j = '0' ; j < '9' ; j++)
	{
		for (i = '0' ; i <= '9' ; i++)
		{
			if (!((i == j) || (j > i)))
			{
				putchar(j);
				putchar(i);
				if (!(i == '9' && j == '8'))
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
