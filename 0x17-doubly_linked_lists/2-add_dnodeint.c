#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlinklist
 * @head: pointer to head node of the double linked list
 * @n: the data to be contained in the new node
 *
 * Return: address of new element, or NULL if failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *temp;

	temp = malloc(sizeof(dlistint_t));

	if (temp == NULL)
		return (NULL);
	temp->n = n;
	temp->prev = NULL;
	temp->next = *head;

	if (*head != NULL)
		(*head)->prev = temp;

	*head = temp;

	return (temp);
}
