#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * if there is a left child, replaces it and sets the previous
 * as its own left child
 * @parent: node to inside left child in
 * @value: value to store in new node
 *
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->right = NULL;

	if (parent->left)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	else
		new->left = NULL;

	parent->left = new;
	return (new);
}
