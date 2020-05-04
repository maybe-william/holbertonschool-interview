#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_insert_node - finds the node to insert the child in
 * @root: the root of the tree
 * @height: the current node height
 * @maxheight: the max tree height
 * Return: the node to enter the child in
 */
binary_tree_t *find_insert_node(binary_tree_t *root, int height, int maxheight)
{
	binary_tree_t *x;
	binary_tree_t *y;

	if ((root->left) && !(root->right))
	return (root);
	if (!(root->left || root->right))
	{
	if (height == maxheight)
		return (NULL);
	else
		return (root);
	}

	x = find_insert_node(root->left, height + 1, maxheight);
	y = find_insert_node(root->right, height + 1, maxheight);
	if (x)
		return (x);
	else
		return (y);
}


/**
 * change - change an item with its parent
 * @item: the item
 * @parent: the parent
 */
void change(binary_tree_t *item, binary_tree_t *parent)
{
	binary_tree_t *grandpapi = parent->parent;
	binary_tree_t *brother = NULL;
	binary_tree_t *leftson = item->left;
	binary_tree_t *rightson = item->right;
	int l_or_r, l_or_r_dad = 0;

	if (item == parent->left)
	{
		brother = parent->right;
		l_or_r = 1;
	}
	else
	{
		brother = parent->left;
		l_or_r = -1;
	}
	l_or_r_dad = (grandpapi && (parent == grandpapi->left)) ? -1 : 1;
	if (l_or_r > 0)
	{
		item->right = brother;
		item->left = parent;
	}
	else
	{
		item->left = brother;
		item->right = parent;
	}
	if (brother)
		brother->parent = item;
	item->parent = grandpapi;
	parent->parent = item;
	parent->left = leftson;
	parent->right = rightson;
	if (grandpapi)
	{
		if (l_or_r_dad > 0)
			grandpapi->right = item;
		else
			grandpapi->left = item;
	}
}



/**
 * max_heapify - turn heap into heap
 * @x: the current bubble-up node
 * Return: the root of the heapified tree
 */
heap_t *max_heapify(binary_tree_t *x)
{
	binary_tree_t *y;

	y = x;
	while (y->parent && y->n > y->parent->n)
		change(y, y->parent);
	while (y->parent)
		y = y->parent;
	return ((heap_t *)y);
}



/**
 * heap_insert - function description
 * @root: parameter description
 * @value: parameter description
 * Return: return description
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *x;
	binary_tree_t *to_insert;
	binary_tree_t *temp;
	int h = 0;

	if (!root)
		return (NULL);
	x = binary_tree_node(NULL, value);
	if (x == NULL)
		return (NULL);
	if (!(*root))
	{
		*root = x;
		return (x);
	}
	temp = *root;
	while (temp->left)
	{
		temp = temp->left;
		h = h + 1;
	}
	to_insert = find_insert_node(*root, 0, h);
	if (!to_insert)
	{
		to_insert = *root;
		while (to_insert->left)
			to_insert = to_insert->left;
	}
	if (to_insert->left)
		to_insert->right = x;
	else
		to_insert->left = x;
	x->parent = to_insert;
	*root = max_heapify(x);
	return (x);
}
