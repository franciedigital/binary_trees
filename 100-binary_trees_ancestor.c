#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of 2 nodes
 * @first: first node
 * @second: second node
 *
 * Return: pointer to ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_tmp, *second_tmp, *first_par, *second_par;

	if (!first || !second)
		return (NULL);

	first_par = (binary_tree_t *)first;
	second_par = (binary_tree_t *)second;

	while (first_par && second_par)
	{
		first_tmp = first_par;
		second_tmp = second_par;

		while (first_tmp)
		{
			if (first_tmp == second_tmp)
				return (first_tmp);
			first_tmp = first_tmp->parent;
		}

		first_tmp = first_par;
		while (second_tmp)
		{
			if (second_tmp == first_tmp)
				return (second_tmp);
			second_tmp = second_tmp->parent;
		}
		first_par = first_par->parent;
		second_par = second_par->parent;
	}

	return (NULL);
}
