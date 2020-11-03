#include "binary_trees.h"
/**
 * avl_tree - recursive function to build a tree
 * @array: sorted array
 * @start: array's start
 * @end: array's end
 * @parent: parent node
 * Return: pointer to header node
 **/
avl_t *avl_tree(int *array, int start, int end, avl_t *parent)
{
		int mid;
		avl_t *node;

		if (start > end)
			return (NULL);
		mid = (start + end) / 2;
		node = malloc(sizeof(avl_t));
		if (!node)
			return (NULL);
		node->n = array[mid];
		node->parent = parent;
		node->left = avl_tree(array, start, mid - 1, node);
		node->right = avl_tree(array, mid + 1, end, node);
		return (node);
}

/**
 * sorted_array_to_avl - builds a tree out of sorted array
 * @array: pointer to the first element of the array to be converted
 * @size:  number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
		if (!array)
			return (NULL);
		return (avl_tree(array, 0, size - 1, NULL));
}
