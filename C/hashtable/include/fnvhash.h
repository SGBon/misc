#ifndef FNVHASH_H
#define FNVHASH_H

#include <stdint.h>
#include <stddef.h>

/* computes a hash using the FNV algorithm */

/*
 * data - data to be hashed
 * len - length in bytes of data
 */
uint64_t fnv_hash(uint8_t *data, size_t len);
#endif // header guard
