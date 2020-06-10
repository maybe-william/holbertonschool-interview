#include "lists.h"

/**
 * check_cycle - check if a linked list has a cycle in it
 * @list: the linked list
 * Return: 0 if the list has no cycle, 1 if it has a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = NULL;
	listint_t *fast = NULL;

	if (!list || !(list->next) || !(list->next->next))
		return (0);
	slow = list;
	fast = list->next;
	while (1)
	{

	fast = fast->next;
	if (!fast)
		return (0);
	if (fast == slow)
		return (1);

	fast = fast->next;
	if (!fast)
		return (0);
	if (fast == slow)
		return (1);

	slow = slow->next;
	}
}
