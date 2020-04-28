#include "lists.h"

/**
 * insert_node - insert a node in a sorted linked list
 * @head: the head of the list
 * @number: the number to put into the node
 * Return: the new node's address or NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *curr;
	listint_t *after;

	if (!head)
		return (NULL);
	if (!*head)
		return (add_nodeint_end(head, (const int) n));

	curr = *head;
	while (curr->next && curr->next->n <= n)
	{
		curr = curr->next;
	}

	after = curr->next;
	curr->next = NULL;
	add_nodeint_end(&curr, (const int) number);
	new = curr->next;
	if (!new)
		return (NULL);
	new->next = after;
	return (new);
}
