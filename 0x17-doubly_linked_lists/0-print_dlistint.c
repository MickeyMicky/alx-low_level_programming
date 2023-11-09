#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - fucntion that prints a doubly linked list
 * @h: head of doubly linked list
 *
 * Return: number of nodes in DLL
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t n_nodes = 0;
	const dlistint_t *temp;

	temp = h;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		n_nodes++;
	}
	return (n_nodes);
}
