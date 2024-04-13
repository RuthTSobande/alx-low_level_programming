#include "hash_tables.h"
/**
 * hash_table_get - function that retrieves a value associated with a key
 * @ht: table for look into
 * @key: looking for
 * Return: value associated with the element, NULL if key couldn't be found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *aux = NULL;

	if (strcmp(key, "") == 0 || key == NULL || ht == NULL)
		return (NULL);

	index = key_index((unsigned char *) key, ht->size);
	aux = ht->array[index];
	if (ht->array[index] != NULL)
	{
		if (strcmp(key, aux->key) == 0)
			return (aux->value);
		while (aux)
		{
			if (strcmp(key, aux->key) == 0)
				return (aux->value);
			aux = aux->next;
		}
	}
	return (NULL);
}
