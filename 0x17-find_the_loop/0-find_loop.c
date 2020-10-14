#include "lists.h"

/**
 * find_listint_loop - find the start of a loop in a linked list
 * @head: the head of the linked list
 * Return: NULL if no loop, otherwise, the node where it starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *a = head;
	listint_t *b = head;

	if (head == NULL || head->next == NULL)
	{
		return (NULL);
	}

	b = b->next;
	while (1)
	{
		if (a == b)
			return (find_listint_loop(head->next));
		if (b == NULL)
			return (NULL);
		if (b == head)
			return (head);
		a = a->next;
		b = b->next;
		if (b == NULL)
			return (NULL);
		if (b == head)
			return (head);
		b = b->next;
	}
}
