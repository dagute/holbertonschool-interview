#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head
 * @number: number to add
 * Return: the address of the new node, or NULL if it failed
 */
 listint_t *insert_node(listint_t **head, int number)
 {
    listint_t *newone, *temp, *aux;
    int x;

    newone = malloc(sizeof(listint_t));
    if (newone == NULL)
    {
	    return (NULL);
    }
    newone->n = number;

    if (number == 0)
    {
	    newone->next = *head;
	    *head = newone;
	    return (newone);
    }
    else
    {
	    temp = *head;
	    aux = temp->next;
        x = 0;
	    while (aux->n < number)
	    {
		    if (aux->next != NULL)
		    {
			    temp = aux;
			    aux = temp->next;
	    	}
		    else
		    {
			    newone->next = NULL;
			    aux->next = newone;
			    return (newone);
		    }
	    }
    x++;    
	newone->next = temp->next;
	temp->next = newone;
	return (newone);
    }
}
