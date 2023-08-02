#include "main.h"

/**
 * _sqrt - function that returns the natural square root of a number.
 * @n: number
 * @start: range
 * @end: range
 * Return: Integer
 */

int _sqrt(int n, int start, int end)
{

	if (n < 0)
	{
		return (-1);
	}
	if (n == 0 || n == 1)
	{
		return (n);
	}

	if (start <= end)
	{
		int mid = start + (end - start) / 2;
		int sqr = mid * mid;

		if (sqr == n)
		{
			return (mid);
		}
		if (sqr < n)
		{
			return (_sqrt(n, mid + 1, end));
		}
		else
		{
			return (_sqrt(n, start, mid - 1));
		}
	}
	return (-1);
}

/**
 * _sqrt_recursion - function that returns the natural square root of a number.
 * @n: number
 * Return: square root of a number
 */

int _sqrt_recursion(int n)
{
	return (_sqrt(n, 0, n));
}
