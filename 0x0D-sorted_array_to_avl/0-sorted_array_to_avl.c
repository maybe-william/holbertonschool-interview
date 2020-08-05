#include "binary_trees.h"

/**
 * add_node - function description
 * @par: parameter description
 * Return: return description
 */
avl_t *add_node(avl_t *par)
{
	avl_t *new;

	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);
	new->parent = par;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

/**
 * build_frame - function description
 * @root: parameter description
 * @levels: parameter description
 * @current_level: parameter description
 * @extras: parameter description
 * Return: return description
 */
avl_t *build_frame(avl_t *root, int levels, int current_level, int *extras)
{
	avl_t *res = NULL;

	if (current_level >= levels)
	{
		if ((*extras) <= 0)
		{
			return (root);
		}
		else
		{
			root->right = add_node(root);
			*extras = (*extras) - 1;
			if (root->right == NULL)
				return (NULL);
			if ((*extras) > 0)
			{
				root->left = add_node(root);
				*extras = (*extras) - 1;
				if (root->left == NULL)
					return (NULL);
			}
			return (root->right);
		}
	}
	else
	{
		root->right = add_node(root);
		if (root->right == NULL)
			return (NULL);
		res = build_frame(root->right, levels, current_level + 1, extras);
		if (res == NULL)
			return (NULL);
		root->left = add_node(root);
		if (root->left == NULL)
			return (NULL);
		res = build_frame(root->left, levels, current_level + 1, extras);
		if (res == NULL)
			return (NULL);
	}
	return (root);
}

/**
 * fill_frame - function description
 * @frame: parameter description
 * @array: parameter description
 * @ind: parameter description
 * Return: return description
 */
int fill_frame(avl_t *frame, int *array, int ind)
{
	int newind = ind;

	if (frame->left)
		newind = fill_frame(frame->left, array, newind);

	frame->n = array[newind];
	newind++;

	if (frame->right)
		newind = fill_frame(frame->right, array, newind);

	return (newind);
}


/**
 * sorted_array_to_avl - function description
 * @array: parameter description
 * @size: parameter description
 * Return: return description
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	avl_t *succ = NULL;
	int levels = 0;
	int extras = 0;
	int *pow2 = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192}

	if (size <= 0)
		return (NULL);

	tree = add_node(NULL);
	if (tree == NULL)
		return (NULL);

	while ((pow2[levels] - 1) <= size)
		levels++;
	levels--;

	extras = size - (pow2[levels] - 1);

	succ = build_frame(tree, levels, 0, &extras);
	if (succ == NULL)
		return (NULL);
	fill_frame(tree, array, 0);

	return (tree);
}
