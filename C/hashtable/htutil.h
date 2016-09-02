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

#endif // header guard
