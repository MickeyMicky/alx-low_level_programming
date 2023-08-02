#include "main.h"

int _prime(int n, int i);

/**
 * is_prime_number - function that returns 1 if prime else 0
 * @n: number
 * Return: 1 or 0 
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (_prime(n, n - 1));
}

/**
 * _prime - function that calculates if a number is prime recursively
 * @n: number
 * @i: iterator
 * Return: 1 if n is prime else 0
 */

int _prime(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0 && i > 0)
		return (0);
	return (_prime(n, i - 1));
}
