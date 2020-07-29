#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head
 * @number: number to add
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *act = NULL;
	listint_t *newone = NULL;

	if (!head)
		return (NULL);
	act = *head;
	newone = malloc(sizeof(listint_t));
	newone->n = number;
	newone->next = NULL;

	if (!act)
	{
		*head = newone;
		return (newone);
	}
	if (number < act->n)
	{
		newone->next = act;
		*head = newone;
		return (newone);
	}
	while (act->next && act->next->n <= number)
		act = act->next;
	newone->next = act->next;
	act->next = newone;
	return (newone);
}
