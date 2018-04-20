#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 20

void *helloWorld(void *p) {
    long id = (long)p;
    printf("Hello World %d\n", id);
}

int main(){
    pthread_t threads[NUM_THREADS];
    long i;

    for(i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, helloWorld, (void *)i);
    }

    for(i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    return 0;
}