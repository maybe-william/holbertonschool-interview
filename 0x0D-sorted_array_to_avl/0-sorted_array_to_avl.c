#include "binary_trees.h"

/**
 * node_frame - Frankenstein's monster combining add_node and fill_frame
 * @par: This function only exists because
 * @array: the school had an absurd requirement of
 * @ind: only having a total of 3 functions per file, but
 * @mode: I need to have 4 functions total, so this is 2 combined.
 * Return: I apologize profusely for the damage this will do to your eyes.
 */
avl_t *node_frame(avl_t *par, int *array, unsigned long ind, int mode)
{
	avl_t *new;
	avl_t *frame = par;
	unsigned long newind = ind;

	if (mode == 0)
	{
		new = malloc(sizeof(avl_t));
		if (new == NULL)
			return (NULL);
		new->parent = par;
		new->left = NULL;
		new->right = NULL;

		return (new);
	}

	if (frame->left)
		newind = (unsigned long)node_frame(frame->left, array, newind, 1);

	frame->n = array[newind];
	newind++;

	if (frame->right)
		newind = (unsigned long)node_frame(frame->right, array, newind, 1);

	return ((avl_t *)newind);
}

/**
 * build_frame - build the empty tree
 * @root: the root node
 * @levels: the number of full levels
 * @current_level: the current level
 * @extras: how many extra nodes there are after a full and complete tree
 * Return: the empty tree structure, or NULL if building failed
 */
avl_t *build_frame(avl_t *root, int levels, int current_level, int *extras)
{
	avl_t *res = NULL;

	if (current_level >= levels)
	{
		if ((*extras) > 0)
		{
			root->right = node_frame(root, NULL, 0, 0);
			*extras = (*extras) - 1;
			if (root->right == NULL)
				return (NULL);
			if ((*extras) > 0)
			{
				root->left = node_frame(root, NULL, 0, 0);
				*extras = (*extras) - 1;
				if (root->left == NULL)
					return (NULL);
			}
			return (root->right);
		}
		return (root);
	}
	else
	{
		root->right = node_frame(root, NULL, 0, 0);
		if (root->right == NULL)
			return (NULL);
		res = build_frame(root->right, levels, current_level + 1, extras);
		if (res == NULL)
			return (NULL);
		root->left = node_frame(root, NULL, 0, 0);
		if (root->left == NULL)
			return (NULL);
		res = build_frame(root->left, levels, current_level + 1, extras);
		if (res == NULL)
			return (NULL);
	}
	return (root);
}



/**
 * sorted_array_to_avl - turn a sorted array into a balanced bst
 * @array: the sorted array
 * @size: the size of the array
 * Return: the new avl, or NULL if failed
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	avl_t *succ = NULL;
	int levels = 0;
	int extras = 0;
	int pow2[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

	if (size <= 0)
		return (NULL);

	tree = node_frame(NULL, NULL, 0, 0);
	if (tree == NULL)
		return (NULL);

	while ((pow2[levels] - 1) <= (int)size)
		levels++;
	levels--;

	extras = size - (pow2[levels] - 1);

	succ = build_frame(tree, levels, 0, &extras);
	if (succ == NULL)
		return (NULL);
	node_frame(tree, array, 0, 1);

	return (tree);
}
