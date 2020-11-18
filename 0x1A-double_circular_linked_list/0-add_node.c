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

	if (list == NULL)
		return (NULL);
	node = malloc(sizeof(List));
	if (node == NULL)
		return (NULL);

	if (str == NULL)
		node->str = NULL;
	else
		node->str = strdup((const char *) str);

	head = *list;
	if (head == NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		*list = node;
		return (node);
	}
	if (head->next == NULL && head->prev == NULL)
	{
		head->next = node;
		head->prev = node;
		node->next = head;
		node->prev = head;
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

	if (list == NULL)
		return (NULL);
	node = malloc(sizeof(List));
	if (node == NULL)
		return (NULL);

	if (str == NULL)
		node->str = NULL;
	else
		node->str = strdup((const char *) str);

	head = *list;
	if (head == NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		*list = node;
		return (node);
	}
	if (head->next == NULL && head->prev == NULL)
	{
		head->next = node;
		head->prev = node;
		node->next = head;
		node->prev = head;
		return (node);
	}
	head->prev->next = node;
	node->prev = head->prev;
	node->next = head;
	head->prev = node;
	return (node);
}
