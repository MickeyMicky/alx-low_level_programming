#include <stdio.h>

/**
 * main - print out size of various type
 * Return: always 0 (Sucess)
 */

int main(void)
{
	char c;
	int i;
	long int lt;
	long long int llt;
	float f;

	printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(c));
	printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(i));
	printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(lt));
	printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(llt));
	printf("Size of an float: %lu byte(s)\n", (unsigned long)sizeof(f));
	return (0);
}
