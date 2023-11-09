#include "lists.h"

/**
 * sum_dlistint - function that returns the sum of all
 * the data (n) of a dlistint_t linked list
 * @head: pointer to head
 *
 * Return: sum of all data else 0 if DLL is NULL
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
