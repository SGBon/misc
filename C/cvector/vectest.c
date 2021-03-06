#include <stdio.h>
#include "cvector.h"

int main(){
	struct vector vec;
	/* can make vector like this */
	//vector_init(&vec, sizeof(float));
	/* or like this */
	VECTOR_CREATE(&vec,float);

	float r = 12.3f;
	vector_add(&vec,&r);
	r = 1.0f;
	vector_add(&vec,&r);
	vector_get(&vec,0,&r);

	printf("Value at %d is %f\n",0,r);

	printf("Testing expansion\n");
	for(size_t i = 0; i < 50; ++i){
		float j = r*i;
		vector_add(&vec, &j);
	}

	printf("Testing retrieval\n");
	printf("[");
	for(size_t i = 0; i < 50;++i){
		vector_get(&vec,i,&r);
		printf("%f, ",r);
	}
	printf("]\n");

	printf("Testing shrinking\n");
	const size_t before = vec.size;
	for(size_t i = 0; i < 25; ++i){
		vector_pop(&vec,&r);
		printf("%f\n",r);
	}
	printf("before: %lu, after: %lu\n",before,vec.size);

	vector_destroy(&vec);
	return 0;
}
