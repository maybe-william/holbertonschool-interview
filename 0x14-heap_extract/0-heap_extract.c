#include "binary_trees.h"

/**
 * swap_nodes - swap two nodes pointers
 * @node1: pointer to node1
 * @node2: pointer to node2
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
	if (node1 == node2)
		return;
	node1->n = (node1->n) ^ (node2->n);
	node2->n = (node1->n) ^ (node2->n);
	node1->n = (node1->n) ^ (node2->n);
}

/**
 * get_height - get the heap height
 * @root: the root of the tree
 * @height: the hight of the tree so far
 * Return: the tallest height
 */
int get_height(heap_t *root, int height)
{
	int left, right;

	if (root->left)
		left = get_height(root->left, height + 1);
	else
		left = height;

	if (root->right)
		right = get_height(root->right, height + 1);
	else
		right = height;

	if (left > right)
		return (left);
	return (right);
}

/**
 * find_last_node - get the last node in a tree
 * @root: the root of the tree
 * @level: the current depth
 * @max_height: the tallest the tree is
 * Return: the node deepest in the tree
 */
heap_t *find_last_node(heap_t *root, int level, int max_height)
{
	heap_t *left;
	heap_t *right;

	if (level == max_height)
		return (root);
	left = NULL;
	right = NULL;
	if (root->left)
		left = find_last_node(root->left, level + 1, max_height);
	if (root->right)
		right = find_last_node(root->right, level + 1, max_height);

	if (right)
		return (right);
	return (left);
}

/**
 * heap_extract - extract a number from a heap and re heapify
 * @root: the root of the heap
 * Return: the value extracted
 */
int heap_extract(heap_t **root)
{
	heap_t *temp;
	heap_t *left;
	heap_t *right;
	heap_t *contender;
	int val = 0;

	if (!root || !(*root))
		return (0);
	val = (*root)->n;
	temp = find_last_node(*root, 0, get_height(*root, 0));
	if (temp == *root)
	{
		free(temp);
		*root = NULL;
		return (val);
	}
	swap_nodes(*root, temp);
	if (temp->parent->left == temp)
		temp->parent->left = NULL;
	else
		temp->parent->right = NULL;
	free(temp);
	temp = *root;
	while (1)
	{
		left = temp->left;
		right = temp->right;
		contender = left;
		if (left && right && (left->n < right->n))
			contender = right;
		if (!left && !right)
			break;
		if (contender->n > temp->n)
			swap_nodes(temp, contender);
		else
			break;
		temp = contender;
	}
	return (val);
}
