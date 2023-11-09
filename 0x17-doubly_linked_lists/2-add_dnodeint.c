#include "lists.h"
#include <stdlib.h>

dlistint_t *Create_Node(const int n);

/**
 * add_dnodeint - Function that adds a node to the head
 *                of a doubly linked list
 * @head: double pointer to the head
 * @n: data
 *
 * Return: pointer to new element else NULL on failure.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *n_node = NULL;
	dlistint_t *temp = NULL;

	n_node = Create_Node(n);
	if (!n_node)
		return (NULL);

	if (!head || !(*head)) /* NULL DLL */
	{
		*head = n_node;
		return (n_node);
	}
	else /* DLL exists */
	{
		temp = *head;
		temp->prev = n_node;
		*head = n_node;
		n_node->next = temp;
		return (n_node);
	}

	return (NULL);
}

/**
 * Create_Node - function that creates a new DLL node with data
 * @n: data to add to node
 *
 * Return: pointer to new node
 */
dlistint_t *Create_Node(const int n)
{
	dlistint_t *new_node = NULL;

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;

	return (new_node);
}
