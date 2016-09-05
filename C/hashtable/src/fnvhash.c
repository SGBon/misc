#include "fnvhash.h"

#define FNV_OFFSET_BASIS 0xcbf29ce484222325
#define FNV_PRIME 0x100000001b3

uint64_t fnv_hash(uint8_t *data, size_t len){
  size_t i;
  uint64_t hash = FNV_OFFSET_BASIS;

  for(i = 0;i < len;i++){
    hash = hash * FNV_PRIME;
    hash = hash ^ data[i];
  }
  return hash;
}
