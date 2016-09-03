#include <stdio.h>
#include "hashtable.h"

int main(){
  struct hashtable ht;

  hashtable_init(&ht,1024,sizeof(int),sizeof(int));

  for(int i = 0; i < 20;i++){
    int value = i * 2;
    hashtable_set(&ht,&i,&value);
  }

  /* test remove */
  {
    int key = 5;
    hashtable_remove(&ht,&key);
  }

  /* test value retrieval */
  for(int i = 0; i < 20; i++){
    int value = 0;
    if(hashtable_get(&ht,&i,&value) == HT_KEY_NOT_FOUND){
      printf("Key not found\n");
    }else{
      printf("%d -> %d\n",i,value);
    }
  }

  /* test overwriting */
  {
    int key = 3;
    int value = 20;
    int ret = 0;
    hashtable_set(&ht,&key,&value);
    hashtable_get(&ht,&key,&ret);
    printf("%d -> %d\n",key,ret);
  }

  hashtable_destroy(&ht);

  return 0;
}
