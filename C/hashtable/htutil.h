#ifndef HT_UTIL_H
#define HT_UTIL_H
#include "httype.h"

/*
 * get element with key in linked list
 */
struct hashtable_entry *find_entry(struct hashtable_entry *root, void* key, size_t key_size);

/*
 * get the last element in linked list, O(n)
 */
struct hashtable_entry *find_end(struct hashtable_entry *root);

/*
 * free memory used up by bin, including root
 */
void clear_bin(struct hashtable_entry *root);

/*
 * Allocates dynamic memory for a hashtable_entry
 * memory should be freed using ht_entry_destroy or
 * manually
 */
struct hashtable_entry *ht_entry_create(void *key, size_t key_size, void *value, size_t value_size);

/*
 * free memory used up by entry
 */
void ht_entry_destroy(struct hashtable_entry* entry);

/*
 * for stopping program in case of error
 */
void raise_error(const char *errormsg);

/*
 * check if x is a power of two
 */
uint8_t isPow2 (size_t x);

#endif // header guard
