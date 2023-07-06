#include "binary_trees.h"

/**
 * count_nodes - counts nodes in a binary tree
 * @tree: the tree
 *
 * Return: number of nodes
 */
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * binary_tree_is_full - checks -f a binary tree is full
 * @tree: the tree
 *
 * Return: 1 if full and 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* tree is full if number of nodes is odd */
	return (count_nodes(tree) % 2);
}
