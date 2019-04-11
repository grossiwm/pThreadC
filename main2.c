#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_thread(void *void_pointer) {
    //int_ptr receberá o valor o ponteiro para o valor de i
    int *int_ptr = (int *) void_pointer;
    uint t = (uint) pthread_self();
    printf("Eu sou a Thread%d e meu ID é %u.\n", *int_ptr, t);

}

int main()
{
    int n;
    printf("\n Digite o número de thread que deseja criar: ");
    scanf("%d", &n);

    printf("\n Você escolheu criar %d threads. \n", n);

    pthread_t array_of_threads[n];

    int i = 0;
    while (++i <= n) {
        pthread_create(&array_of_threads[i], NULL, print_thread, &i);
        pthread_join(array_of_threads[i], NULL);
    }

    return 0;
}