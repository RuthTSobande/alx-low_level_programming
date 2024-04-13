#include "hash_tables.h"
/**
 * hash_table_print - Function that prints a hash table
 * @ht: hash table to be print
 * Return: anything
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	int flag = 0;
	hash_node_t *aux = NULL;

	if (ht == NULL)
		return;
	printf("{");
	while (i < ht->size)
	{
		if (ht->array[i])
		{
			aux = ht->array[i];
			while (aux)
			{
				if (flag == 1)
					printf(", ");
				printf("'%s': '%s'", aux->key, aux->value);
				aux = aux->next;
				flag = 1;
			}
		}
		i++;
	}
	printf("}\n");
}
