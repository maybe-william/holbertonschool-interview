#include "list.h"


/**
 * add_node_begin - Add a node to the beginning of a ring queue
 * @list: the ring queue
 * @str: the string to add
 * Return: the added node
 */
List *add_node_begin(List **list, char *str)
{
	List *node;
	List *head;

	if (list == NULL || str == NULL)
		return (NULL);
	node = malloc(sizeof(List *));
	if (node == NULL)
		return (NULL);

	node->str = strdup((const char *) str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}

	head = *list;
	if (head == NULL)
	{
		node->next = node;
		node->prev = node;
		*list = node;
		return (node);
	}
	head->prev->next = node;
	node->prev = head->prev;
	node->next = head;
	head->prev = node;
	*list = node;
	return (node);
}


/**
 * add_node_end - Add a node to the end of a ring queue
 * @list: the ring queue
 * @str: the string to add
 * Return: the added node
 */
List *add_node_end(List **list, char *str)
{
	List *node;
	List *head;

	if (list == NULL || str == NULL)
		return (NULL);
	node = malloc(sizeof(List *));
	if (node == NULL)
		return (NULL);

	node->str = strdup((const char *) str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}

	head = *list;
	if (head == NULL)
	{
		node->next = node;
		node->prev = node;
		*list = node;
		return (node);
	}
	head->prev->next = node;
	node->prev = head->prev;
	node->next = head;
	head->prev = node;
	return (node);
}
