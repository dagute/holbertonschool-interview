#include "lists.h"
/**
 * reverse_linked_list - reverses a listint_t linked list
 * @head: double pointer to list
 * Return: a pointer to the first node of the reversed list
 */
void reverse_linked_list(listint_t **head)
{
	listint_t *ant, *sig;

	ant = NULL;

	while (*head)
	{
		sig = (*head)->next;
		(*head)->next = ant;
		ant = *head;
		*head = sig;
	}
	*head = ant;
}

/**
 * compare_lists - compares two linked lists
 * @a: pointer to head of first list
 * @b: pointer to head of second list
 * Return: 1 if true, 0 if false
 */
int compare_lists(listint_t *a, listint_t *b)
{
	while (a != NULL && b != NULL)
	{
		if (a->n == b->n)
		{
			a = a->next;
			b = b->next;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}


/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 1 if true, 0 if false
 */
int is_palindrome(listint_t **head)
{
	listint_t *first = *head, *second = *head, *prev = *head;
	int res = 0;

	if (!second || !second->next)
		return (1);
	while (second && second->next)
	{
		second = second->next->next;
		prev = first;
		first = first->next;
	}
	if (second)
	{
		second = first;
		first = first->next;
	}
	prev->next = NULL;
	reverse_linked_list(&first);
	res = compare_lists(*head, first);
	reverse_linked_list(&first);
	if (second)
	{
		prev->next = second;
		second->next = first;
	}
	else
		prev->next = first;
	return (res);
}
