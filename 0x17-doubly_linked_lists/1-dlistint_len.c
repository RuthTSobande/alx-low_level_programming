#include "lists.h"

/**
 * dlistint_len - prints the number elements in a dlistint_t
 * @h: pointer to head node of the linked list
 *
 * Return: the number of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}
