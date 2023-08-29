#include "lists.h"

size_t print_listint_safe(const listint_t *head)
{
	size_t num = 0;
	const listint_t *current = head;
	const listint_t *check_loop = head;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		num++;
		current = current->next;

		if (current == check_loop)
		{
			fprintf(stderr, "Linked list has a loop\n");
			exit(98);
		}

		if (check_loop != NULL)
		{
			check_loop = check_loop->next;
			if (check_loop != NULL)
			{
				check_loop = check_loop->next;
			}
		}
	}

	return (num);
}
