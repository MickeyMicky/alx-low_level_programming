#include <stdio>

/**
 * main - print out the line without using puts or printf
 * Return: always 1 (sucess)
 */

int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}
