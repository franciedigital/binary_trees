#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a binary search tree
 * @tree: the tree
 * @value: the value to insert
 *
 * Return: the created node or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *temp, *parent;

	if (!(*tree))
	{
		new = (bst_t *)binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	temp = *tree;
	while (temp)
	{
		parent = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else
			return (NULL);
	}

	new = (bst_t *)binary_tree_node(parent, value);
	if (value > parent->n)
		parent->right = new;
	else
		parent->left = new;

	return (new);
}
