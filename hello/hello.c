#include <pthread.h>
#include <stdio.h>

void *hello_world(void *args) {
    int *n = args;
    printf("Hello from thread %d\n", *n);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    pthread_t thread;
    int n = 1;
    if (pthread_create(&thread, NULL, hello_world, &n)) {
        printf("Error creating thread\n");
    }
    if (pthread_join(thread, NULL)) {
        printf("Error joining thread\n");
    }
}
