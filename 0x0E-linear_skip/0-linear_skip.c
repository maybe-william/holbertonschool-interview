#include "search.h"


/**
 * get_next - get next express
 * @ptr: the pointer
 * Return: the next express
 */
skiplist_t *get_next(skiplist_t *ptr)
{
	skiplist_t *x = ptr;

	if (ptr->express)
		return (ptr->express);
	while (x->next)
		x = x->next;
	return (x);
}


/**
 * linear_skip - Linear search of a skip list
 * @list: the list
 * @value: the value to search for
 * Return: a pointer to the node containing the value, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	unsigned int size, start, end, j;
	skiplist_t *prev;
	skiplist_t *nex;

	if (!list)
		return (NULL);
	prev = NULL;
	nex = list;
	while (nex->express)
		nex = nex->express;
	while (nex->next)
		nex = nex->next;
	size = nex->index + 1;
	nex = list;
	start = 0;
	end = size - 1;
	while ((nex->index + 1) < size && (nex->n) < value)
	{
		prev = nex;
		nex = get_next(nex);
		j = nex->index;
		if (nex->next)
			printf("Value checked at index [%d] = [%d]\n", j, nex->n);
	}
	if (prev)
		start = prev->index;
	end = nex->index;
	if (prev == nex)
		start = nex->index;
	printf("Value found between indexes [%d] and [%d]\n", start, end);
	j = start;
	while (j < size && j <= end)
	{
		printf("Value checked at index [%d] = [%d]\n", j, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
		j++;
	}
	return (NULL);
}
