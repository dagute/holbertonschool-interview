#include "binary_trees.h"
/**
 * tree_preorder - goes through a binary tree using pre-order traversal
 * @root: pointer root of the tree
 * @node: pointer node in the tree
 * @h: height of tree
 * @l: layer on the tree
 **/
void tree_preorder(heap_t *root, heap_t **node, size_t h, size_t l)
{
	if (!root)
		return;
	if (h == l)
		*node = root;
	l++;
	if (root->left)
		tree_preorder(root->left, node, h, l);
	if (root->right)
		tree_preorder(root->right, node, h, l);
}
/**
 * tree_sorting - binary tree Heapsort
 * @tmp: pointer to the heap root
 * Return: pointer to last node
 **/
heap_t *tree_sorting(heap_t *tmp)
{
	int aux;

	while (tmp->left || tmp->right)
	{
		if (!tmp->right || tmp->left->n > tmp->right->n)
		{
			aux = tmp->n;
			tmp->n = tmp->left->n;
			tmp->left->n = aux;
			tmp = tmp->left;
		}
		else if (!tmp->left || tmp->left->n < tmp->right->n)
		{
			aux = tmp->n;
			tmp->n = tmp->right->n;
			tmp->right->n = aux;
			tmp = tmp->right;
		}

	}
	return (tmp);
}
/**
 * tree_height - Check the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t h_left;
	size_t h_right;

	h_left = tree->left ? 1 + tree_height(tree->left) : 0;
	h_right = tree->right ? 1 + tree_height(tree->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}
/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *tmp, *node;

	if (!root || !*root)
		return (0);
	tmp = *root;
	value = tmp->n;
	if (!tmp->left && !tmp->right)
	{
		*root = NULL;
		free(tmp);
		return (value);
	}
	tree_preorder(tmp, &node, tree_height(tmp), 0);
	tmp = tree_sorting(tmp);
	tmp->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}
