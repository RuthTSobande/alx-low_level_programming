#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the beginning of a dlinklist
 * @head: pointer to head node of the double linked list
 * @n: the data to be contained in the new node
 *
 * Return: address of new element, or NULL if failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp;
	dlistint_t *last;

	temp = malloc(sizeof(dlistint_t));

	if (temp == NULL)
		return (NULL);

	temp->n = n;
	temp->next = NULL;

	if (*head == NULL)
		*head = temp;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;

		temp->prev = last;
		last->next = temp;
	}
	return (*head);
}
