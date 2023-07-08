#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: the node
 *
 * Return: pointer to the sibling node or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *temp;

	if (!node || !node->parent)
		return (NULL);

	temp = node->parent;
	if (temp->left == node)
		return (temp->right);
	else
		return (temp->left);
}
