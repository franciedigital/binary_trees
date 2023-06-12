#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is root
 * @node: the node to check
 *
 * Return: 1 if true and 0 if false
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);

	return (1);
}
