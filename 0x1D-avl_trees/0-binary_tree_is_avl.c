#include "binary_trees.h"

/**
 * check_avl - Recursively check bst property and shape (in order traversal)
 * @node: The starting node to check
 * @last: The last node value checked
 * @max: The deepest depth of the tree so far
 * @min: The shallowest node missing at least one child
 * @depth: The current depth in the tree
 * Return: 0 if not an avl tree (short-circuit behavior), 1 if an avl tree
 */
int check_avl(binary_tree_t *node, int *last, int *max, int *min, int depth)
{
	int result = 1;

	if (node->left)
		result = check_avl(node->left, last, max, min, depth + 1);
	if (result == 0)
		return (0);

	if (depth > *max)
		*max = depth;

	if (!(node->left && node->right))
		if (*min == -2147483648 || depth < *min)
			*min = depth;

	if (*max - *min > 1)
		return (0);

	if (*last >= node->n)
		return (0);

	*last = node->n;

	if (node->right)
		result = check_avl(node->right, last, max, min, depth + 1);
	if (result == 0)
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - Check if a given tree is an avl tree
 * @tree: The starting node
 * Return: 1 if avl tree, 0 if not avl tree
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int last = -2147483648;
	int max = -2147483648;
	int min = -2147483648;

	if (!tree)
		return (0);
	return (check_avl((binary_tree_t *)tree, &last, &max, &min, 0));
}
