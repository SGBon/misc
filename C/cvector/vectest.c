#include <stdio.h>
#include "cvector.h"

int main(){
	struct vector *vec = NULL;
	vector_init(&vec);

	vector_add(vec,12.3);
	vector_add(vec,2.4);
	vector_print(vec);

	vector_add(vec,4.3);
	vector_add(vec,8.5);
	vector_add(vec,88.0);
	vector_print(vec);

	vector_set(vec,1.0,3);
	printf("%f\n",vector_get(vec,3));
	printf("%f\n",vector_pop(vec));
	vector_print(vec);

	int i;
	for(i = 0; i < 100; i++){
		vector_add(vec,i*0.78);
	}
	vector_print(vec);
	for(i = 0;i < 100;i++){
		vector_pop(vec);
	}
	vector_print(vec);

	vector_destroy(vec);
	return 0;
}
