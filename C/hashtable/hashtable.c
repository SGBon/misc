#include "hashtable.h"
#include "htutil.h"
#include "fnvhash.h"

#include <stdlib.h>
#include <string.h>

// methods to bin hashes
enum HT_BIN_METHODS{
  HT_BM_MOD, // modulo
  HT_BM_MASK // bit mask
};

/* elegant solution for determining if a number is a power of two, found on
 http://www.exploringbinary.com/ten-ways-to-check-if-an-integer-is-a-power-of-two-in-c/ */
uint8_t isPow2 (size_t x) {
  return ((x != 0) && !(x & (x - 1)));
}

enum HT_PUB_FLAGS hashtable_init(struct hashtable *ht, size_t length, size_t key_size, size_t value_size){

  ht->length = length;
  ht->key_size = key_size;
  ht->value_size = value_size;

  ht->bins = calloc(length,sizeof(struct hashtable_entry*));
  if(!ht->bins)
    return HT_INIT_ERROR;

  /* here we set what method to use when binning hashed keys,
  we use bitmask when the length is a power of two, otherwise
  we use modulo */
  ht->bin_method = isPow2(length) ? HT_BM_MASK : HT_BM_MOD;

  return HT_SUCCESS;
}

void hashtable_set(struct hashtable *ht, void *key, void *value){
  uint64_t hash = fnv_hash(key,ht->key_size);
  uint64_t bin = (ht->bin_method == HT_BM_MASK) ?
  (hash & (ht->length - 1)) : (hash % ht->length);

  /* new entry to put into table */
  struct hashtable_entry* newentry = malloc(sizeof(struct hashtable_entry));
  newentry->key = malloc(ht->key_size);
  newentry->value = malloc(ht->value_size);
  newentry->next = NULL;

  memcpy(newentry->key,key,ht->key_size);
  memcpy(newentry->value,value,ht->value_size);

  /* if there was no collision, assign it to the first point */
  if(!ht->bins[bin]){
    ht->bins[bin] = newentry;
  }else{
    struct hashtable_entry *last = find_end(ht->bins[bin]);
    last->next = newentry;
  }
}

enum HT_PUB_FLAGS hashtable_get(struct hashtable *ht, void *key, void *retval){
  uint64_t hash = fnv_hash(key,ht->key_size);
  uint64_t bin = (ht->bin_method == HT_BM_MASK) ?
  (hash & (ht->length - 1)) : (hash % ht->length);

  struct hashtable_entry *entry = find_entry(ht->bins[bin],key,ht->key_size);
  if(entry){
    memcpy(retval,entry->value,ht->value_size);
    return HT_SUCCESS;
  }else{
    return HT_KEY_NOT_FOUND;
  }
}

void hashtable_destroy(struct hashtable *ht){
  for(size_t i = 0; i < ht->length;i++){
    clear_bin(ht->bins[i]);
  }
  free(ht->bins);
}
