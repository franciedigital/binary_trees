#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree
 * @tree: the tree
 *
 * Return: pointer to new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (!tree || !tree->left)
		return (NULL);

	new = tree->left;
	if (new->right)
	{
		tree->left = new->right;
		tree->left->parent = tree;
	}
	else
		tree->left = NULL;

	new->right = tree;
	new->parent = tree->parent;
	tree->parent = new;

	return (new);
}
