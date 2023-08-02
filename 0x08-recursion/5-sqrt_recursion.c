#include "main.h"

/**
 * _sqrt - function that returns the natural square root of a number.
 * @n: number
 * @i: iterator
 * Return: function
 */

int _sqrt(int n, int i)
{

	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (_sqrt(n, i + 1));

}

/**
 * _sqrt_recursion - function that returns the natural square root of a number.
 * @n: number
 * Return: square root of a number
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt(n, 0));
}
