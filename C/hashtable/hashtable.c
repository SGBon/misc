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

void hashtable_destroy(struct hashtable *ht){
  for(size_t i = 0; i < ht->length;i++){
    clear_bin(ht->bins[i]);
    ht->bins[i] = NULL;
  }
  free(ht->bins);
}

void hashtable_set(struct hashtable *ht, void *key, void *value){
  uint64_t hash = fnv_hash(key,ht->key_size);
  uint64_t bin = (ht->bin_method == HT_BM_MASK) ?
  (hash & (ht->length - 1)) : (hash % ht->length);

  /* if there was no collision, assign it to the first point */
  if(!ht->bins[bin]){
    ht->bins[bin] = ht_entry_create(key,ht->key_size,value,ht->value_size);
  }else{
    /* first check if key is already in table */
    struct hashtable_entry *possible = find_entry(ht->bins[bin],key,ht->key_size);
    if(possible){
      /* overwrite the value */
      memcpy(possible->value,value,ht->value_size);
    }else{
      struct hashtable_entry *last = find_end(ht->bins[bin]);
      last->next = ht_entry_create(key,ht->key_size,value,ht->value_size);
    }
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


void hashtable_remove(struct hashtable *ht, void *key){
  uint64_t hash = fnv_hash(key,ht->key_size);
  uint64_t bin = (ht->bin_method == HT_BM_MASK) ?
  (hash & (ht->length - 1)) : (hash % ht->length);

  struct hashtable_entry *toremove = find_entry(ht->bins[bin],key,ht->key_size);
  /* if there is more than one entry in bin */
  if(toremove != ht->bins[bin]){
    struct hashtable_entry *prev = find_prev(ht->bins[bin],toremove);
    struct hashtable_entry *next = toremove->next;
    prev->next = next;
  }
  ht_entry_destroy(toremove);
  ht->bins[bin] = NULL;
}
