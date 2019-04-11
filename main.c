#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Função que incrementa x até vlor de x ser maior ou igual a 100
void *inc_x(void *x_void_ptr)
{
	/* incremente x até 100 */
	int *x_ptr = (int *)x_void_ptr;
	while(++(*x_ptr) < 100){
		printf("\nx = %d\n", *x_ptr);
	};

	printf("x increment finished successfuly!\n");

	/* the function must return something - NULL will do */
	return NULL;
}


int main() {
	int x = 0, y = 0;

	printf("\nx = %d, y = %d\n", x, y);

	pthread_t inc_x_thread;

	// pthread_crete() retorna 0 se sucesso
	if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
		
		fprintf(stderr, "Error creating thread.\n");
		return 1;
	}

	while(++y < 100){
		printf("\ny = %d\n", y);
	};

	printf("y increment finished.\n");
	
	if(pthread_join(inc_x_thread, NULL)) {
		fprintf(stderr, "Error joining thread.\n");
		return 2;
	}

	printf("x = %d, y = %d\n", x, y);

	return 0;

}
