#include "binary_trees.h"

/**
 * find_m - find max between two numbers
 * @a: first number
 * @b: second number
 *
 * Return: max
 */
int find_m(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

/**
 * find_hgt - finds the height of a tree
 * @tree: tree to find height of
 *
 * Return: height or 0
 */
size_t find_hgt(const binary_tree_t *tree)
{
	size_t height;

	if (!tree)
		return (0);

	height = find_m(find_hgt(tree->left), find_hgt(tree->right));

	return (height + 1);
}

/**
 * count - counts nodes in a binary tree
 * @tree: the tree
 *
 * Return: number of nodes
 */
int count(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count(tree->left) + count(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the tree
 *
 * Return: 1 if true and 0 if false
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int levels, tree_nodes, p_nodes = 1;

	if (!tree)
		return (0);

	levels = find_hgt(tree);

	while (levels != 0)
	{
		p_nodes *= 2;
		levels--;
	}

	p_nodes -= 1;
	tree_nodes = count(tree);

	if (tree_nodes == p_nodes)
		return (1);
	else
		return (0);
}
