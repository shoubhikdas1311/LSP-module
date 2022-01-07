#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define MAX                 3
int critical = 0;
pthread_t threads[MAX];
pthread_rwlock_t lock;
void *foo()
{
    pthread_rwlock_wrlock(&lock);
    printf("foo %d started \n", critical);
    //three threads - 0, 1, 2
    for (size_t i = 0; i < 1000000; i++)
    {
        /* code */
    }/*
    while (1)
    {
        /* code 
    }*/
    
    critical++;
    printf("return value %d\n", pthread_rwlock_wrlock(&lock));
    printf("foo %d finished \n", critical);
    pthread_rwlock_unlock(&lock);
    
    return NULL;
}

int main(int argc, char const *argv[])
{
    int i = 0;
    printf("%d\n", pthread_rwlock_init(&lock, NULL));
    for (i = 0; i < MAX; i++)
    {
        printf("%d\n", pthread_create(&(threads[i]), NULL, &foo, NULL));
    }
    while (1)
    {
        if (critical == 3)
        {
            printf("%d", pthread_rwlock_destroy(&lock));
            exit(0);
        }
        
        /* code */
    }
    return 0;
}
//read lock - rdlock - Only read updated shared data
//write lock - wrlock - Synchronize updated shared data