#include "main.h"

/**
 * _isalpha - function that checks for alphabetic character
 * @c: char to be checked
 * Return: 1 if c is a letter else 0
 */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
