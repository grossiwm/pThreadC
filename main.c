#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// #define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>



void *print_thread(void *void_pointer) {
    //int_ptr receberá o valor o ponteiro para o valor de i

    pid_t tid;
    tid = syscall(SYS_gettid);

    int *int_ptr = (int *) void_pointer;
    printf("Eu sou a Thread%d e meu ID é pthread_self: %u ou com gettid: %u.\n", *int_ptr, (uint) pthread_self(), tid);
    pthread_exit(NULL);
    return NULL;
}

int main()
{
    int n = 0;
    printf("\n Digite o número de thread que deseja criar: ");
    scanf("%d", &n);

    printf("\n Você escolheu criar %d threads. \n", n);

    pthread_t array_of_threads[n];

    int i = 0;
    while (++i <= n) {
        pthread_create(&array_of_threads[i], NULL, print_thread, &i);
    }

    i = 0;
    while (++i <= n) {
        pthread_join(array_of_threads[i], NULL);
    }
    return 0;
}

// Output
//  Digite o número de thread que deseja criar: 3

//  Você escolheu criar 3 threads. 
//     Eu sou a Thread1 e meu ID é 3044779776.
//     Eu sou a Thread1 e meu ID é 3053172480.
//     Eu sou a Thread1 e meu ID é 3061565184.