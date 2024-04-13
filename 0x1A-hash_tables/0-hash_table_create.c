#include "hash_tables.h"
/**
 * hash_table_create - Function that create a hash tables
 * @size: size of the hash table
 * Return: a pointer to the newly created hash table or NULL
 * if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{

	hash_table_t *ptr = NULL;

	if (size < 1)
		return (NULL);

	ptr = malloc(sizeof(hash_table_t));
	if (ptr == NULL)
		return (NULL);

	ptr->array = malloc(size * sizeof(hash_node_t *));
	if (ptr->array == NULL)
		return (NULL);
	memset(ptr->array, 0, size * sizeof(hash_node_t *));

	ptr->size = size;
	return (ptr);
}
