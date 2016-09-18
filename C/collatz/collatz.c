#include <stdio.h>
#include <hashtable.h>
#include "helper.h"

int main(void){
  /* yeah, I made a hashmap to use it like a tree */
  struct hashtable collatz_tree;

  /* 2^16 buckets */
  hashtable_init(&collatz_tree,0x1000,sizeof(uint64_t),sizeof(uint64_t));

  /* let's start from some basis point */
  for(uint64_t i = 1; i < 10000; i++){
    uint64_t value;
    enum HT_PUB_FLAGS state;
    state = hashtable_get(&collatz_tree,&i,&value);
    uint64_t nextkey = i;
    /* we haven't computed here yet */
    while(state == HT_KEY_NOT_FOUND){
      uint64_t nextval = compute_collatz(nextkey);
      hashtable_set(&collatz_tree,&nextkey,&nextval);

      nextkey = nextval;
      state = hashtable_get(&collatz_tree,&nextkey,&value);
    }
  }

  for(uint64_t i = 1; i < 1000000; i++){
    print_sequence(&collatz_tree,i);
  }

  hashtable_destroy(&collatz_tree);

  return 0;
}
