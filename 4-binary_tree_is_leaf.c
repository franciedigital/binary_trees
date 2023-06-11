#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is leaf
 * @node: the node to check
 *
 * Return: 1 if true and 0 if false
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);

	return (1);
}
