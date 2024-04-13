#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	hash_table_t *ht;
	unsigned long int i;

	if (size == 0)
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	table = calloc(1, sizeof(hash_table_t));
	if (table == NULL)
	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	table->size = size;
	table->array = calloc(size, sizeof(hash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	return (table);
	return (ht);
}
  7 changes: 5 additions & 2 deletions7  
0x1A-hash_tables/0-main.c
@@ -3,7 +3,11 @@
#include <stdio.h>
#include "hash_tables.h"


/**
 * main - check the code for
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
@@ -12,4 +16,3 @@ int main(void)
    printf("%p\n", (void *)ht);
    return (EXIT_SUCCESS);
}

 265 changes: 153 additions & 112 deletions265  
0x1A-hash_tables/100-sorted_hash_table.c
@@ -1,178 +1,219 @@
#include "hash_tables.h"

void sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *sbucket = ht->shead;

	if (sbucket == NULL)
	{
		ht->shead = ht->stail = new_node;
		new_node->snext = new_node->sprev = NULL;
		return;
	}
	do {
		if (strcmp(new_node->key, sbucket->key) < 0)
		{
			new_node->snext = sbucket;
			new_node->sprev = sbucket->sprev;

			if (!sbucket->sprev)
				ht->shead = new_node;
			else
				sbucket->sprev->snext = new_node;
			sbucket->sprev = new_node;
			return;
		}
		sbucket = sbucket->snext;
	} while (sbucket);
	new_node->sprev = ht->stail;
	new_node->snext = ht->stail->snext;
	ht->stail->snext = new_node;
	ht->stail = new_node;
}

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	table = calloc(1, sizeof(shash_table_t));
	if (table == NULL)
	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	table->size = size;
	table->array = calloc(size, sizeof(shash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	return (table);
	return (ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *valuecopy, *keycopy;
	shash_node_t  *bucket, *new_node;
	shash_node_t *new, *tmp;
	char *value_copy;
	unsigned long int index;

	if (!ht || !key || !*key || !value)
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	valuecopy = strdup(value);
	if (!valuecopy)

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	bucket = ht->array[index];

	while (bucket)
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (!strcmp(key, bucket->key))
		if (strcmp(tmp->key, key) == 0)
		{
			free(bucket->value);
			bucket->value = valuecopy;
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		bucket = bucket->next;
		tmp = tmp->snext;
	}
	new_node = calloc(1, sizeof(shash_node_t));
	if (new_node == NULL)

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(valuecopy);
		free(value_copy);
		return (0);
	}
	keycopy = strdup(key);
	if (!keycopy)
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (0);
	new_node->key = keycopy;
	new_node->value = valuecopy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	sorted_list(ht, new_node);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	shash_node_t  *bucket;
	shash_node_t *node;
	unsigned long int index;

	if (!ht || !key || !*key)
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	bucket = ht->array[index];
	while (bucket)
	{
		if (!strcmp(key, bucket->key))
			return (bucket->value);
		bucket = bucket->next;
	}
	return (NULL);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *bucket;
	int not_fin = 0;
	shash_node_t *node;

	if (!ht)
	if (ht == NULL)
		return;
	bucket = ht->shead;

	node = ht->shead;
	printf("{");
	while (bucket)
	while (node != NULL)
	{
		if (not_fin)
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
		printf("'%s': '%s'", bucket->key, bucket->value);
		not_fin = 1;
		bucket = bucket->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *bucket;
	int not_fin = 0;
	shash_node_t *node;

	if (!ht)
	if (ht == NULL)
		return;
	bucket = ht->stail;

	node = ht->stail;
	printf("{");
	while (bucket)
	while (node != NULL)
	{
		if (not_fin)
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
		printf("'%s': '%s'", bucket->key, bucket->value);
		not_fin = 1;
		bucket = bucket->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *bucket, *aux_free;
	unsigned long int i = 0;
	shash_table_t *head = ht;
	shash_node_t *node, *tmp;

	if (!ht)
	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	node = ht->shead;
	while (node)
	{
		bucket = ht->array[i];
		while (bucket)
		{
			aux_free = bucket;
			bucket = bucket->next;
			if (aux_free->key)
				free(aux_free->key);
			if (aux_free->value)
				free(aux_free->value);
			free(aux_free);
		}
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}
	free(ht->array);
	free(ht);

	free(head->array);
	free(head);
}
  55 changes: 42 additions & 13 deletions55  
0x1A-hash_tables/hash_tables.h
@@ -1,25 +1,37 @@
#ifndef _HASH_TABLES_H_
#define _HASH_TABLES_H_
#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct hash_node_s - Node of a hash table
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	 char *key;
	 char *value;
	 struct hash_node_s *next;
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;


/**
 * struct hash_table_s - Hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	 unsigned long int size;
	 hash_node_t **array;
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/*functions*/
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
@@ -28,7 +40,15 @@ char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);


/**
 * struct shash_node_s - Node of a sorted hash table
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
	char *key;
@@ -38,6 +58,15 @@ typedef struct shash_node_s
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
	unsigned long int size;
@@ -48,9 +77,9 @@ typedef struct shash_table_s

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
void shash_table_print(const shash_table_t *ht);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
#endif

#endif /* HASH_TABLES_H */
