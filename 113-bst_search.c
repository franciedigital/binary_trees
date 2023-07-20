#include "binary_trees.h"

/**
 * bst_search - searches for a value in a binary search tree
 * @tree: the tree
 * @value: the value to search for
 *
 * Return: the node containing the value or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp;

	if (!tree)
		return (NULL);

	temp = (bst_t *)tree;
	while (temp)
	{
		if (temp->n == value)
			return (temp);

		if (temp->n > value)
			temp = temp->left;
		else if (temp->n < value)
			temp = temp->right;
	}

	return (NULL);
}
