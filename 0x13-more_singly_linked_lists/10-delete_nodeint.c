#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node
 * at index index of a listint_t linked list
 * @head: pointer to the first element onn the linked list
 * @index: index of the node to be delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *curr = *head;
	listint_t *prev = NULL;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (i = 0; i < index && curr != NULL; i++)
	{
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL)
		return (-1);

	prev->next = curr->next;
	free(curr);
	return (1);
}
