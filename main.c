#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

void generateThreadsIndexArray(int *array, int size);
void *print_thread(void *void_pointer);


int main()
{
    int n = 0;
    printf("\n Digite o número de thread que deseja criar: ");
    scanf("%d", &n);

    printf("\n Você escolheu criar %d threads. \n", n);

    pthread_t array_of_threads[n];
    // int id[n]

    int threadsIndexesArray[n];
    generateThreadsIndexArray(threadsIndexesArray, n);

    int i = 0;
    while (i < n) {
        pthread_create(&array_of_threads[i], NULL, print_thread, (void *) &threadsIndexesArray[i]);
        i++;
    }

    i = 0;
    while (i < n) {
        pthread_join(array_of_threads[i], NULL);
        i++;
    }
    return 0;
}

void *print_thread(void *void_pointer) {
    //int_ptr receberá o valor o ponteiro para o valor de i

    pid_t tid;
    tid = syscall(SYS_gettid);

    int *int_ptr = (int *) void_pointer;
    printf("Eu sou a Thread0%d e meu ID é pthread_self: %u ou com gettid: %u.\n", *int_ptr, (uint) pthread_self(), tid);

    return NULL;
}

void generateThreadsIndexArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
      array[i] = i + 1;
    }
}