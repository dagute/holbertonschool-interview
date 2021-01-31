#include "lists.h"
/**
 * find_listint_loop - find the loop in a linked list
 * @head: pointer to a pointer to a list to the first element of a list
 * Return: addrress of the node wherer the loop starts, or NULL if no node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first;
	listint_t *last;

	if (head == NULL)
		return (NULL);

	first = head;
	last = head;

	while (first != NULL && first->next != NULL && first->next->next != NULL)
	{
		last = last->next;
		first = first->next->next;
		if (last == first)
		{
			last = head;
			while (last != first)
			{
				last = last->next;
				first = first->next;
			}
			return (first);
		}
	}
	return (NULL);
}
