#include "htutil.h"
#include <stdlib.h>
#include <string.h>

struct hashtable_entry *find_entry(struct hashtable_entry *root, void* key, size_t key_size){
  struct hashtable_entry *current = root;
  char* first = key;
  char* second = NULL;
  while(current){
    second = current->key;
    if(!strncmp(first,second,key_size)){
      return current;
    }
    current = current->next;
  }
  return NULL;
}

struct hashtable_entry *find_end(struct hashtable_entry* root){
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

void clear_bin(struct hashtable_entry *root){
  /* safety check, if root is NULL */
  if(!root)
    return;

  struct hashtable_entry *tofree;
  /*
  * keep grabbing last element in linked list
  * and free the memory it takes until only root element is left
  * what is this, like O(n^2 - n) ???
  */
  while((tofree = find_end(root)) != root){
    free(tofree->key);
    free(tofree->value);
    free(tofree);
  }
  /* free root element */
  free(root->key);
  free(root->value);
  free(root);
}
