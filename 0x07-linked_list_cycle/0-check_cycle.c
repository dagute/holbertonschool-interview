#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *head = list, *tail = list;

	if (list == NULL)
		return (0);
	while (head->next != NULL && head->next->next != NULL)
	{
		tail = tail->next;
		head = head->next->next;
		if (tail == head)
			return (1);
	}
	return (0);
}