#include "binary_trees.h"

/**
 * check_left - checks the left subtree of a tree
 * @tree: the tree
 * @n: the value to check against
 *
 * Return: 0 if any value in the left subtree is greater than
 * n and 1 otherwise
 */
int check_left(binary_tree_t *tree, int n)
{
	int i;

	if (!tree)
		return (1);

	if (tree->n >= n)
		return (0);

	i = check_left(tree->left, n);
	if (i == 0)
		return (0);
	i = check_left(tree->right, n);
	if (i == 0)
		return (0);

	return (1);
}

/**
 * check_right - checks the right subtree of a tree
 * @tree: the tree
 * @n: the value to check against
 *
 * Return: 0 if any value in the left subtree is less than
 * n and 1 otherwise
 */
int check_right(binary_tree_t *tree, int n)
{
	int i;

	if (!tree)
		return (1);

	if (tree->n <= n)
		return (0);

	i = check_right(tree->left, n);
	if (i == 0)
		return (0);
	i = check_right(tree->right, n);
	if (i == 0)
		return (0);

	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: the tree
 *
 * Return: 1 if true and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = check_left(tree->left, tree->n);
	right = check_right(tree->right, tree->n);

	if (left == 0 || right == 0)
		return (0);

	binary_tree_is_bst(tree->left);
	binary_tree_is_bst(tree->right);

	return (1);
}
