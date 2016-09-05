#ifndef HT_TYPE_H
#define HT_TYPE_H
#include <stdint.h>
#include <stddef.h>


struct hashtable_entry{
  void *key;
  void *value;
  struct hashtable_entry *next; // linked list to next entry in bucket
};

struct hashtable{
  struct hashtable_entry **bins; // bins in hashtable
  size_t length; // number of bins in hashtable
  size_t key_size; // size of keys in bytes
  size_t value_size; // size of values in bytes
  uint8_t bin_method; // method to bin hashes
};

#endif // header guard
