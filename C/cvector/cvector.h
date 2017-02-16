#ifndef CVECTOR_H
#define CVECTOR_H
#include <stddef.h>

/* a c++ like vector for floating points written in C */
struct vector{
	void *values; /* elements in vector */
	size_t next; /* index to next space in vector after last element */
	size_t size; /* size of vector */
	size_t value_size; /* size of single element in vector */
};

enum vector_ret_state{
	VECTOR_RET_FAIL,
	VECTOR_RET_SUCCESS
};

#define VECTOR_CREATE(vec,type) vector_init(vec,sizeof(type));

/* initialize the vector */
void vector_init(struct vector *vec, size_t value_size);

/* free the memory used by the vector */
void vector_destroy(struct vector *vec);

/* adds element to end of vector */
void vector_add(struct vector *vec, void *val);

/* removes and returns the last element
returns 0 if vector is empty */
enum vector_ret_state vector_pop(struct vector*, void *retval);

/* set element at index to value */
void vector_set(struct vector *vec, void *val, size_t index);

/* get element at index */
enum vector_ret_state vector_get(struct vector *vec, size_t index, void *retval);

#endif
