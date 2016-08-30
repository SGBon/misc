#include <stdio.h>
#include "fnvhash.h"

int main(){
  for(size_t i = 0; i < 50; i++){
    uint64_t hashed = fnv_hash((void*) &i,sizeof(i));
    printf("%u %u\n",i,hashed);
  }
  return 0;
}
