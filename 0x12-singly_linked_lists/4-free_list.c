#include <stdlib.h>
#include "lists.h"

/**
 * free_list - function that frees a list_t list
 * @head: list_t list to be free
 */
void free_list(list_t *head)
{
	list_t *te;

	while (head != NULL)
	{
		temp = head->next;
		free(head->str);
		free(temp);
		head = temp;
	}
}
