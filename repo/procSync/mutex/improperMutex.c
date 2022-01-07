#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define MAX                 2
int critical = 0;
pthread_t threads[MAX];
pthread_mutex_t lock;
void SD_sleep()
{
    for (size_t i = 0; i < 1000000; i++)
    { 
    }
}
void *foo()
{
    while (1)
    {
        pthread_mutex_lock(&lock);
        printf("foo %d started \n", critical);    
        critical++;
        SD_sleep();    
        printf("foo %d finished \n", critical);
        pthread_mutex_unlock(&lock);
    }
    
    return NULL;
}
void * zoo()
{
    while (1)
    {
        printf("less\n"); 
        critical--;
        SD_sleep();  
    }
    printf("Greater or equal\n");
}
int main(int argc, char const *argv[])
{
    int i = 0;
    printf("%d\n", pthread_mutex_init(&lock, NULL));
    for (i = 0; i < MAX; i++)
    {
        if (i == 0)
        {
        printf("%d\n", pthread_create(&(threads[i]), NULL, &foo, NULL));
        }
        else
        {
        printf("%d\n", pthread_create(&(threads[i]), NULL, &zoo, NULL));
        }
        
    }
    while (1)
    {
        
    }
    return 0;
}
