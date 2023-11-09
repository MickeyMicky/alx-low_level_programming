#include "lists.h"

dlistint_t *create_node(const int n);

/**
 * add_dnodeint_end - function that adds a node to the end
 * of a doubly linked list
 * @head: double pointer to the head
 * @n: data
 *
 * Return: pointer to new element else NULL on failure.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *n_node = NULL, *temp = NULL;

	n_node = create_node(n);
	if (!n_node)
		return (NULL);

	if (!head || !(*head))
	{
		*head = n_node;
		return (n_node);
	}
	else
	{
		temp = *head;
		while (temp->next) /* advance to end of DLL */
			temp = temp->next;

		n_node->prev = temp;
		temp->next = n_node;

		return (n_node);
	}
	return (NULL);
}

/**
 * create_node - function that creates a new DLL node with data
 * @n: data
 *
 * Return: pointer to new allocated node
 */
dlistint_t *create_node(const int n)
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
