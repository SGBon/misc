#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "httype.h"

enum HT_PUB_FLAGS{
  HT_INIT_ERROR,
  HT_SUCCESS, // general success constant
  HT_KEY_NOT_FOUND // key not found in hashtable when quering
};

/*
 * initializes a hashtable. The hashtable will have length bins,
 * the hashtable entries will have a key of key_size bytes long
 * and values of value_size bytes long. Malloc is called by this
 * function so hashtable_destroy has to be called when ending
 * the program. Returns HT_SUCCESS on success, HT_INIT_ERROR on fail
 */
enum HT_PUB_FLAGS hashtable_init(struct hashtable *ht, size_t length, size_t key_size, size_t value_size);

/*
 * frees the memory taken by ht. Should be called as many times as succesful
 * hashtable_init calls are made
 */
void hashtable_destroy(struct hashtable *ht);

/*
 * sets the value at key to the parameter value. overwrites the value if key
 * already exist
 */
void hashtable_set(struct hashtable *ht, void *key, void *value);

/*
 * Get the value associated with a key
 * returns HT_SUCCESS when value is recieved succesfully,
 * HT_KEY_NOT_FOUND when no associated key pair exist
 * returned value is in retval
 */
enum HT_PUB_FLAGS hashtable_get(struct hashtable *ht, void *key, void *retval);

/*
 * Remove entry from hashtable matching the key
 */
void hashtable_remove(struct hashtable *ht, void *key);
#endif // header guard
