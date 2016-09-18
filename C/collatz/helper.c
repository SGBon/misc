#include <stdio.h>
#include "helper.h"

uint64_t compute_collatz(uint64_t n){
  return ((n & 1u) ? (3*n + 1) : (n/2));
}

void print_sequence(struct hashtable *ht, uint64_t num){
  enum HT_PUB_FLAGS state;
  uint64_t nextkey = num;
  uint64_t nextval = 0;
  uint8_t firsttime = 1;

  /* quit when we hit 1 */
  while(nextval != 1){
    state = hashtable_get(ht,&nextkey,&nextval);
    if(state == HT_KEY_NOT_FOUND){
      break;
    }else if(firsttime){
      firsttime = 0;
      printf("%lu -> ",num);
    }
    printf("%lu -> ",nextval);
    nextkey = nextval;
  }
  if(!firsttime)
    printf("\n");
}
