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
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * check_avl - check if a binary tree is avl
 * @tree: the tree
 *
 * Return: 1 if true and 0 if false
 */
int check_avl(const binary_tree_t *tree)
{
	int r_height = 0, l_height = 0, left, right, is_avl;

	if (!tree)
		return (1);

	left = check_left(tree->left, tree->n);
	right = check_right(tree->right, tree->n);

	if (left == 0 || right == 0)
		return (0);

	if (tree->right)
		r_height = _height(tree->right) + 1;
	if (tree->left)
		l_height = _height(tree->left) + 1;

	if (r_height - l_height > 1 || l_height - r_height > 1)
		return (0);

	is_avl = check_avl(tree->left);
	if (is_avl == 0)
		return (0);
	is_avl = check_avl(tree->right);
	if (is_avl == 0)
		return (0);

	return (1);
}


/**
 * binary_tree_is_avl - checks if a binary tree is avl
 * @tree: the tree
 *
 * Return: 1 if true and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_avl(tree));
}
