#include "htutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hashtable_entry *find_entry(struct hashtable_entry *root, void *key, size_t key_size){
  struct hashtable_entry *current = root;
  char* first = key;
  char* second = NULL;
  while(current){
    second = current->key;
    /* strncmp returns 0 when both strings are equal */
    if(strncmp(first,second,key_size) == 0){
      return current;
    }
    current = current->next;
  }
  return NULL;
}

struct hashtable_entry *find_end(struct hashtable_entry *root){
  struct hashtable_entry *current = root->next;
  /* base case, root is last element */
  if(current == NULL)
    return root;

  /* run through linked list until next is NULL, meaning we are at end */
  while(current->next){
    current = current->next;
  }
  return current;
}

struct hashtable_entry *find_prev(struct hashtable_entry *root, struct hashtable_entry *entry){
  /* safety check */
  if(!root->next || root == entry)
    return NULL;

  struct hashtable_entry *current = root;
  while(current->next != entry){
    current = current->next;
  }
  return current;
}

void clear_bin(struct hashtable_entry *root){
  /* safety check, if root is NULL */
  if(!root)
    return;

  struct hashtable_entry *tofree = find_end(root);
  /*
  * keep grabbing last element in linked list
  * and free the memory it takes until only root element is left
  * what is this, like O(n^2 - n) ???
  */
  while(tofree){
    ht_entry_destroy(tofree);
    if(tofree == root)
      break;
    tofree = find_prev(root,tofree);
    tofree->next = NULL;
  }
}

struct hashtable_entry *ht_entry_create(void *key, size_t key_size, void *value, size_t value_size){
  struct hashtable_entry* newentry = malloc(sizeof(struct hashtable_entry));
  if(!newentry){
    raise_error("Memory allocation failure!");
  }
  newentry->key = malloc(key_size);
  if(!newentry->key){
    raise_error("Memory allocation failure!");
  }
  newentry->value = malloc(value_size);
  if(!newentry->value){
    raise_error("Memory allocation failure!");
  }
  newentry->next = NULL;

  memcpy(newentry->key,key,key_size);
  memcpy(newentry->value,value,value_size);
  return newentry;
}

void ht_entry_destroy(struct hashtable_entry* entry){
  if(entry){
    free(entry->key);
    free(entry->value);
    free(entry);
  }
}

void raise_error(const char *errormsg){
  fprintf(stderr,"%s\n",errormsg);
  exit(1);
}

/* elegant solution for determining if a number is a power of two, found on
 http://www.exploringbinary.com/ten-ways-to-check-if-an-integer-is-a-power-of-two-in-c/ */
uint8_t isPow2 (size_t x) {
  return ((x != 0) && !(x & (x - 1)));
}
