#include "binary_trees.h"

/**
 * array_to_bst - builds a binary tree from an array
 * @array: the array
 * @size: the size of the array
 *
 * Return: pointer to root node or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	if (i == size)
		return (root);

	return (NULL);
}
