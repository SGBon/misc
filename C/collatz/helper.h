#include <hashtable.h>

/*
 * compute a number using the function of the collatz conjecture
 * The function f(n) goes:
 * if n is even, f(n) = n/2
 * if n is odd, f(n) = 3n+1
 */
uint64_t compute_collatz(uint64_t n);

/* print a sequence in the collatz conjecture starting from some number */
void print_sequence(struct hashtable *ht,uint64_t num);
