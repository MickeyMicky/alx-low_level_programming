#include "main.h"

/**
 * _sqrt_recursion - function that returns the natural square root of a number.
 * @n: number
 * Return: square root of a number
 */

int _sqrt_recursion(int n)
{
	int start;
	int end;

	if (n < 0)
	{
		return (-1);
	}
	if (n == 0 || n == 1)
	{
		return (n);
	}

	start = 1;
	end = n;

	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		int sqr = mid * mid;

		if (sqr == n)
		{
			return (mid);
		}
		else if (sqr < n)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return (end);
}
