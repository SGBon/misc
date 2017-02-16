#include <stdio.h>
#include "cvector.h"

int main(){
	struct vector vec;
	vector_init(&vec, sizeof(float));

	float r = 12.3f;
	vector_add(&vec,&r);
	r = 1.0f;
	vector_add(&vec,&r);
	vector_get(&vec,0,&r);

	printf("Value at %d is %f\n",0,r);

	for(size_t i = 0; i < 50; ++i){
		float j = r*i;
		vector_add(&vec, &j);
	}

	printf("[");
	for(size_t i = 0; i < 50;++i){
		vector_get(&vec,i,&r);
		printf("%f, ",r);
	}
	printf("]\n");

	vector_destroy(&vec);
	return 0;
}
