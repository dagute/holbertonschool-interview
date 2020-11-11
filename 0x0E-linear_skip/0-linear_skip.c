#include "search.h"
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: the value to search for
 * Return: NULL or a pointer to the node with the value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
		skiplist_t *pass;

		if (!list)
			return (NULL);
		pass = list;
		while (pass->express)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				pass->express->index, pass->express->n);
			if (pass->express->n >= value)
			{
				printf("Value found between indexes [%lu] and [%lu]\n",
					pass->index, pass->express->index);
				break;
			}
			pass = pass->express;
		}
		if (!pass->express)
		{
			list = pass;
			while (list->next)
				list = list->next;
			printf("Value found between indexes [%lu] and [%lu]\n",
				pass->index, list->index);
		}
		list = pass;
		while (list != pass->express)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				list->index, list->n);
			if (list->n == value)
				break;
			list = list->next;
		}
		if (list != pass->express)
			return (list);
		return (NULL);
}
