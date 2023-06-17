#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node to measure depth of
 *
 * Return: 0 or depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;
	const binary_tree_t *temp;

	if (!tree)
		return (0);

	for (temp = tree; temp->parent; temp = temp->parent)
		depth++;

	return (depth);
}
