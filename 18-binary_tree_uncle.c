#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: the node
 *
 * Return: pointer to the uncle node or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *temp;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	temp = node->parent->parent;
	if (temp->left == node->parent)
		return (temp->right);
	else
		return (temp->left);
}
