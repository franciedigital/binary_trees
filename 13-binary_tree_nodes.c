#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the number of nodes with at least 1 child
 * @tree: the tree
 *
 * Return: number of nodes or 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int count;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
		count = 1;
	else
		count = 0;

	return (count + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
}
