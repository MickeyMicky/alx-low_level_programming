#include <stdlib.h>
#include "lists.h"

/**
 * list_len - function that returns the number of
 * elements in a linked list_t list
 * @h: pointer to the list_t list
 *
 * Return: number of elements in h
 */
size_t list_len(const list_t *h)
{
	size_t c = 0;

	while (h != NULL)
	{
		h = h->next;
		c++;
	}

	return (c);
}
