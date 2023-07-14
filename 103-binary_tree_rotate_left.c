#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on a binary tree
 * @tree: the tree
 *
 * Return: pointer to new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (!tree || !tree->right)
		return (NULL);

	new = tree->right;
	if (new->left)
	{
		tree->right = new->left;
		tree->right->parent = tree;
	}
	else
		tree->right = NULL;

	new->left = tree;
	new->parent = tree->parent;
	tree->parent = new;

	return (new);
}
