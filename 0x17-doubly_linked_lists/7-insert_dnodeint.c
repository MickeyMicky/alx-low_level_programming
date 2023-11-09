#include "lists.h"
#include <stdlib.h>

/**
 * create_node_ - function that creates a new DLL node with data
 * @n: data
 *
 * Return: pointer to new allocated node
 */
dlistint_t *create_node_(const int n)
{
	dlistint_t *n_node = NULL;

	n_node = malloc(sizeof(dlistint_t));
	if (n_node == NULL)
		return (NULL);

	n_node->next = NULL;
	n_node->prev = NULL;
	n_node->n = n;

	return (n_node);
}

/**
 * insert_dnodeint_at_index - function that inserts a new node
 * at a given position.
 * @h: double pointer to the head
 * @idx: to insert new node
 * @n: data
 *
 * Return: pointer to new node else NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = NULL, *temp = NULL;
	unsigned int i = 0;

	new_node = create_node_(n);
	if (new_node == NULL)
		return (NULL);
	if (!h || !(*h)) /* NULL DLL */
		*h = new_node;
	else /* DLL exists */
	{
		temp = *h;
		while (idx != i++ && temp->next)
			temp = temp->next;
		if (temp->next)
			new_node->prev = temp->prev;
		else
			new_node->prev = temp;
		if (idx == i)
		{
			temp->next = new_node;
			new_node->prev = temp;
		}
		else if (idx == i - 1) /* insert at head or middle */
		{
			if (temp->prev)
				temp->prev->next = new_node;
			else
				*h = new_node;
			temp->prev = new_node;
			new_node->next = temp;
		}
		else /* index is out of range */
		{
			free(new_node);
			return (NULL);
		}
	}
	return (new_node);
}
