#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * main - program that adds positive numbers
 * @argc: count
 * @argv: vector
 *
 * Return: 0 (success) or 1 (error)
 */

int main(int argc, char *argv[])
{
	int sum = 0;
	int i, j, num;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		const char *arg = argv[i];
		bool is_valid = true;

		for (j = 0; arg[j] != '\0'; j++)
		{
			if (!isdigit(arg[j]))
			{
				is_valid = false;
				break;
			}
		}

		if (is_valid)
		{
			num = atoi(arg);
			if (num > 0)
			{
				sum += num;
			}
			else
			{
				printf("Error\n");
				return (1);
			}
		} else
		{
			printf("Error\n");
			return (1);
		}
	}
	printf("%d\n", sum);
	return (0);
}
