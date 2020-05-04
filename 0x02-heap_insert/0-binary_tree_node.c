#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - function description
 * @parent: parameter description
 * @value: parameter description
 * Return: return description
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *x;

	x = malloc(sizeof(binary_tree_t));
	if (x == NULL)
		return (NULL);
	x->parent = parent;
	x->n = value;
	x->left = NULL;
	x->right = NULL;
	return (x);
}
