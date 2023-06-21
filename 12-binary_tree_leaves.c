#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the number of leaves in a tree
 * @tree: the tree
 *
 * Return: number of leaves or 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int count;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		count = 1;
	else
		count = 0;

	return (count + binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
}
