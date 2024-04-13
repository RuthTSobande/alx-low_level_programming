#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100

typedef struct shash_node {
    char *key;
    char *value;
    struct shash_node *next;
    struct shash_node *sprev;
    struct shash_node *snext;
} shash_node_t;

typedef struct shash_table {
    shash_node_t **array;
    shash_node_t *shead;
    shash_node_t *stail;
    int size;
} shash_table_t;

unsigned long djb2(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

shash_table_t *shash_table_create(int size) {
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (!ht) {
        return NULL;
    }

    ht->array = malloc(sizeof(shash_node_t*) * size);
    if (!ht->array) {
        free(ht);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        ht->array[i] = NULL;
    }

    ht->shead = NULL;
    ht->stail = NULL;
    ht->size = size;

    return ht;
}

void shash_table_set(shash_table_t *ht, char *key, char *value) {
    unsigned long hash_value = djb2(key);
    int index = hash_value % ht->size;

    shash_node_t *current = ht->array[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            // Key already exists, update value
            free(current->value);
            current->value = strdup(value);
            return;
        }
        current = current->next;
    }

    // Key does not exist, create new node
    shash_node_t *new_node = malloc(sizeof(shash_node_t));
    if (!new_node) {
        return;
    }

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    // Insert new node in sorted list
    shash_node_t *sprev = NULL;
    shash_node_t *snext = ht->shead;
    while (snext && strcmp(snext->key, key) < 0) {
        sprev = snext;
        snext = snext->snext;
    }

    new_node->sprev = sprev;
    new_node->snext = snext;
    if (sprev) {
        sprev->snext = new_node;
    } else {
        ht->shead = new_node;
    }
    if (snext) {
        snext->sprev = new_node;
    } else {
        ht->stail = new_node;
    }
}

char *shash_table_get(shash_table_t *ht, char *key) {
    unsigned long hash_value = djb2(key);
    int index = hash_value % ht->size;

    shash_node_t *current = ht->array[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

void shash_table_print
