# Project 0x1A-hash_tables

## Task 0: Hash Table Creation

Write a function to create a hash table.

Prototype: 'hash_table_t *hash_table_create(unsigned long int size);'
where 'size' denotes the size of the array.
Returns a pointer to the newly created hash table.
If an error occurs, the function should return NULL.

## Task 1: djb2 Hash Function

Implement the djb2 algorithm for hashing.

Prototype: 'unsigned long int hash_djb2(const unsigned char *str);'
You are permitted to copy and paste the function from the provided page.

## Task 2: Key to Index

Write a function to obtain the index of a key.

Prototype: 'unsigned long int key_index(const unsigned char *key, unsigned long int size);'
where 'key' represents the key and 'size' denotes the array size of the hash table.
This function should utilize the previously written 'hash_djb2' function.
Returns the index where the key/value pair should be stored in the hash table array.

## Task 3: Add Element to Hash Table

Write a function to add an element to the hash table.

Prototype: 'int hash_table_set(hash_table_t *ht, const char *key, const char *value);'
Where 'ht' is the hash table to which the key/value is to be added or updated,
'key' represents the key (which cannot be an empty string),
and 'value' represents the value associated with the key (which must be duplicated and can be an empty string).
Returns: 1 if successful, 0 otherwise.
In the event of a collision, the new node should be added at the beginning of the list.

## Task 4: Retrieve Value Associated with Key

Write a function to retrieve the value associated with a key.

Prototype: 'char *hash_table_get(const hash_table_t *ht, const char *key);'
where 'ht' is the hash table to be searched and 'key' is the key to look for.
Returns the value associated with the element, or NULL if the key couldn’t be found.

## Task 5: Print Hash Table

Write a function to print a hash table.

Prototype: 'void hash_table_print(const hash_table_t *ht);'
where 'ht' represents the hash table.
The key/value pairs should be printed in the order they appear in the hash table array.
Order: array, list
Format: see example
If 'ht' is NULL, nothing should be printed.

## Task 6: Delete Hash Table

Write a function to delete a hash table.

Prototype: 'void hash_table_delete(hash_table_t *ht);'
where 'ht' is the hash table to be deleted.

## End of Tasks