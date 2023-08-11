#include "binary_trees.h"

/**
 * array_to_avl - builds a binary tree from an array
 * @array: the array
 * @size: the size of the array
 *
 * Return: pointer to root node or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	if (i == size)
		return (root);

	return (NULL);
}
