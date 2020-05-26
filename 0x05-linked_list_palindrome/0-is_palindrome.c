#include "lists.h"

/**
 * get_length - calculate list length
 * @head: the head of the list
 * Return: the list length
 */
unsigned int get_length(listint_t *head)
{
	unsigned int len = 0;
	listint_t *temp = head;

	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

/**
 * set_j - point j to end and reverse from middle to end
 * @head: the head of the list
 * @j: a pointer to the j pointer
 * @len: the length of the linked list
 */
void set_j(listint_t *head, listint_t **j, unsigned int len)
{
	int curr = 0;
	listint_t *jprev = NULL;
	listint_t *temp = NULL;

	*j = head;
	while (*j)
	{
		temp = *j;
		*j = (*j)->next;
		if ((unsigned int)curr >= (len + 1) / 2)
		{
			/*reverse the connection*/
			temp->next = jprev;
		}
		jprev = temp;
		curr++;
	}
	*j = jprev;
}

/**
 * done_cond - calculate if done checking palindrome
 * @i: the pointer in front
 * @j: the pointer in the back
 * Return: true or false whether done or not checking palindrome
 */
int done_cond(listint_t *i, listint_t *j)
{
	int done_odd;
	int done_even;

	done_odd = (i == j);
	done_even = (j->next == i && i->next != j);

	return (done_odd || done_even);
}

/**
 * is_palindrome - check if a linked list is a palindrome
 * @head: the head of the list
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	unsigned int len = 0;
	listint_t *i = NULL;
	listint_t *j = NULL;
	listint_t *temp = NULL;
	listint_t *jprev = NULL;
	int pal = 1;

	if (!head)
		return (0);

	len = get_length(*head);
	if (len == 0 || len == 1)
		return (1);
	i = *head;
	set_j(*head, &j, len);

	/*loop backwards, swapping back the j pointer at every step until done*/
	while (!done_cond(i, j))
	{
		if (i->n != j->n)
			pal = 0;

		i = i->next;

		temp = j;
		j = j->next;

		temp->next = jprev;
		jprev = temp;
	}
	return (pal);
}
