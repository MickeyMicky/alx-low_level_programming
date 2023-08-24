#include <stdio.h>

/**
 * print_this_first - function to be printed before main execute
 */
void print_this_first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

/**
 * first_this - ensure it prints first
 *
 * Description: use the constructor attribute to ensure
 *              that message print first before main
 */
void __attribute__((constructor)) first_this()
{
	print_this_first();
}
