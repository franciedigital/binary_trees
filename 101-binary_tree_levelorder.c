#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
size_t height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + height(tree->left) : 0;
	height_r = tree->right ? 1 + height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * current_level - executes a function on the current level of a tree
 * @tree: the tree
 * @func: the function to executes
 * @level: the current level
 *
 * Return: void
 */
void current_level(binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		current_level(tree->left, func, level - 1);
		current_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree usind level order
 * @tree: the tree
 * @func: a function to execute
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h, i;

	if (!tree || !func)
		return;

	h = height(tree) + 1;

	for (i = 1; i <= h; i++)
		current_level((binary_tree_t *)tree, func, i);
}
