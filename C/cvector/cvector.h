/* a c++ like vector for floating points written in C */

struct vector;

/* initialize the vector */
void init_vector(struct vector**);

/* free the memory used by the vector */
void destroy_vector(struct vector*);

/* adds element to end of vector */
void add_vector(struct vector* , float);

/* removes and returns the last element
returns 0 if vector is empty */
float pop_vector(struct vector*);

/* set element at index to value */
void set_vector(struct vector*,float,unsigned int);

/* get element at index */
float get_vector(struct vector*,unsigned int);

/* print contents of vector */
void print_vector(struct vector*);
