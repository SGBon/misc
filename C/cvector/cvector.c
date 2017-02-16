#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cvector.h"

#define INITIAL_SIZE 20 /* initial size of vector */
#define DELTA_LENGTH 10 /* amount of memory space to add or remove when resizing */

void vector_init(struct vector *vec, size_t value_size){
	vec->values = NULL;
	vec->next = 0;
	vec->size = 0;
	vec->value_size = value_size;
}

void vector_destroy(struct vector* vec){
	if(vec->values != NULL)
		free(vec->values);
}

void vector_add(struct vector* vec,void *val){
	/* if values are yet to be allocated */
	if(vec->values == NULL){
		vec->values = malloc(vec->value_size * INITIAL_SIZE);
		vec->size = INITIAL_SIZE;
	}
	/* if we need more space for values */
	else if(vec->next == vec->size){
		void* newspace = realloc(vec->values,(vec->size + DELTA_LENGTH)*vec->value_size);
		if(newspace != NULL){
			vec->values = newspace;
			vec->size += DELTA_LENGTH;
		}else{
			vector_destroy(vec);
			printf("Error reallocating memory when expanding\n");
			exit(1);
		}
	}
	//vec->values[vec->next++] = val;
	memcpy(vec->values + (vec->value_size * vec->next),val,vec->value_size);
	++vec->next;
}

enum vector_ret_state vector_pop(struct vector *vec, void *retval){
	if(vec->next > 0){
		--vec->next;
		memcpy(retval,vec->values + (vec->value_size * vec->next),vec->value_size);
		/* shrink values array if it is much larger than necessary */
		if(vec->size > (vec->next + DELTA_LENGTH) && vec->size > DELTA_LENGTH){
			void* newspace = realloc(vec->values,(vec->size - DELTA_LENGTH)*vec->value_size);
			if(newspace != NULL){
				vec->values = newspace;
				vec->size -= DELTA_LENGTH;
			}else{
				vector_destroy(vec);
				printf("Error reallocating memory when shrinking\n");
				exit(1);
			}
		}
		return VECTOR_RET_SUCCESS;
	}else{
		printf("Error popping vector: vector is empty\n");
		return VECTOR_RET_FAIL;
	}
}

void vector_set(struct vector* vec,void *val, size_t index){
	if(index >= vec->next){
		printf("index out of range\n");
		return;
	}else{
		//vec->values[index] = val;
		memcpy(vec->values + (vec->value_size * index),val,vec->value_size);
	}
}

enum vector_ret_state vector_get(struct vector* vec, size_t index, void *retval){
	if(index >= vec->next){
		printf("index out of range, returning 0\n");
		return VECTOR_RET_FAIL;
	}else{
		//return vec->values[index];
		memcpy(retval,vec->values + (vec->value_size * index),vec->value_size);
		return VECTOR_RET_SUCCESS;
	}
}

void vector_print(struct vector* vec){
	if(vec->next > 0){
		unsigned int i;
		printf("[");
		for(i = 0;i<vec->next;i++)
			printf("%f%c ",vec->values[i],(i<vec->next-1 ? ',' : ']'));
		printf("\n");
	}else{
		printf("Could not print vector: Vector is empty\n");
	}
}
