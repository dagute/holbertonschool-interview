#include "binary_trees.h"

/**
 * binary_s_tree - checks if tree is a binary search tree
 * @node: current node being checked
 * @min: integer indicating the left boundary of the current node's value
 * @max: integer indicating the right boundary of the current node's value
 * @height: height of the current binary tree level
 * Return: 1 if tree is a valid BST otherwise 0
 */
int binary_s_tree(const binary_tree_t *node, int min, int max,
		int *height)
{
	int l_h = 0;
	int r_h = 0;

	if (!node)
		return (1);

	if (node->n >= max || node->n <= min)
		return (0);

	if (!binary_s_tree(node->left, min, node->n, &l_h) ||
			!binary_s_tree(node->right, node->n,
				max, &r_h))
		return (0);
	*height = (l_h > r_h ? l_h : r_h) + 1;
	return (abs(l_h - r_h) < 2);
}

/**
 * binary_s_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer tot the root node of the tree to check
 * Return: 1 if tree is a valid AVL, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);
	return (binary_s_tree(tree, INT_MIN, INT_MAX, &height));
}
