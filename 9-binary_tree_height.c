#include "binary_trees.h"

/**
 * find_max - find max between two numbers
 * @a: first number
 * @b: second number
 *
 * Return: max
 */
int find_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

/**
 * find_height - finds the height of a tree
 * @tree: tree to find height of
 *
 * Return: height or 0
 */
size_t find_height(const binary_tree_t *tree)
{
	size_t height;

	if (!tree)
		return (0);

	height = find_max(find_height(tree->left), find_height(tree->right));

	return (height + 1);
}


/**
 * binary_tree_height - finds the height of a binary_tree
 * @tree: pointer to root node
 *
 * Return: height or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (find_height(tree) - 1);
}
