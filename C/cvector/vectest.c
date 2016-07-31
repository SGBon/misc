#include <stdio.h>
#include "cvector.h"

int main(){
	struct vector *vec = NULL;
	init_vector(&vec);

	add_vector(vec,12.3);
	add_vector(vec,2.4);
	print_vector(vec);

	add_vector(vec,4.3);
	add_vector(vec,8.5);
	add_vector(vec,88.0);
	print_vector(vec);

	set_vector(vec,1.0,3);
	printf("%f\n",get_vector(vec,3));
	printf("%f\n",pop_vector(vec));
	print_vector(vec);

	destroy_vector(vec);
}
