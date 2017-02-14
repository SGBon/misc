#ifndef CVECTOR_H
#define CVECTOR_H
/* a c++ like vector for floating points written in C */

struct vector{
	float *values; /* elements in vector */
	unsigned int next; /* index to next space in vector after last element */
	unsigned int size; /* memory size of vector */
};

/* initialize the vector */
void vector_init(struct vector**);

/* free the memory used by the vector */
void vector_destroy(struct vector*);

/* adds element to end of vector */
void vector_add(struct vector* , float);

/* removes and returns the last element
returns 0 if vector is empty */
float vector_pop(struct vector*);

/* set element at index to value */
void vector_set(struct vector*,float,unsigned int);

/* get element at index */
float vector_get(struct vector*,unsigned int);

/* print contents of vector */
void vector_print(struct vector*);
#endif
