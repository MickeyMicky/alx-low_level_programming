#include "main.h"

/**
 * _islower - function that checks for lowercase character
 *@c: char to be checked
 * Return: int 0 or 1
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
