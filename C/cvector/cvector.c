#include <stdlib.h>
#include <stdio.h>
#include "cvector.h"

#define INITIAL_SIZE 20 /* initial size of vector */
#define DELTA_LENGTH 10 /* amount of memory space to add or remove when resizing */

struct vector{
	float *values; /* elements in vector */
	unsigned int next; /* index to next space in vector after last element */
	unsigned int size; /* memory size of vector */
};

void vector_init(struct vector **vec){
	struct vector *retvec = malloc(sizeof(struct vector));
	if(vec == NULL){
		printf("unable to allocate memory\n");
		exit(1);
	}
	retvec->values = NULL;
	retvec->next = 0;
	retvec->size = 0;
	*vec = retvec;
}

void vector_destroy(struct vector* vec){
	if(vec->values != NULL)
		free(vec->values);
	free(vec);
}

void vector_add(struct vector* vec,float val){
	/* if values are yet to be allocated */
	if(vec == NULL){
		printf("???\n");
		return;
	}
	if(vec->values == NULL){
		vec->values = (float*) malloc(sizeof(float) * INITIAL_SIZE);
		vec->size = INITIAL_SIZE;
	}
	/* if we need more space for values */
	else if(vec->next == vec->size){
		float* newspace = NULL;
		newspace = (float*) realloc(vec->values,vec->size + DELTA_LENGTH);
		if(newspace != NULL){
			vec->values = newspace;
			vec->size += DELTA_LENGTH;
		}else{
			vector_destroy(vec);
			printf("Error reallocating memory when expanding\n");
			exit(1);
		}
	}
	vec->values[vec->next++] = val;
}

float vector_pop(struct vector* vec){
	if(vec->next > 0){
		float retval = vec->values[--vec->next];
		/* shrink values array if it is much larger than necessary */
		if(vec->size > (vec->next + DELTA_LENGTH) && vec->size > DELTA_LENGTH){
			float* newspace = NULL;
			newspace = (float *) realloc(vec->values,vec->size - DELTA_LENGTH);
			if(newspace != NULL){
				vec->values = newspace;
				vec->size -= DELTA_LENGTH;
			}else{
				vector_destroy(vec);
				printf("Erroy reallocating memory when shrinking\n");
				exit(1);
			}
		}
		return retval;
	}else{
		printf("Error popping vector: vector is empty\n");
		return 0;
	}
}

void vector_set(struct vector* vec,float val, unsigned int index){
	if(index >= vec->next){
		printf("index out of range\n");
		return;
	}else{
		vec->values[index] = val;
	}
}

float vector_get(struct vector* vec,unsigned int index){
	if(index >= vec->next){
		printf("index out of range, returning 0\n");
		return 0;
	}else{
		return vec->values[index];
	}
}

void vector_print(struct vector* vec){
	if(vec->next > 0){
		unsigned int i;
		printf("[");
		for(i = 0;i<vec->next;i++)
			printf("%f%c ",vec->values[i],(i<vec->next-1 ? 'c' : ']'));
		printf("\n");
	}else{
		printf("Could not print vector: Vector is empty\n");
	}
}
