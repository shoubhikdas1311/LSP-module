#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
sem_t sema;
pthread_mutex_t mut_l;
pthread_t th[6];
int critical = 2;
void SD_sleep()
{
    for (size_t i = 0; i < 1000000000; i++)
    {
    }
}
void *threader(void * arg)
{
    sem_wait(&sema);
    while (critical < 6)
    {
    printf("thread no %d %d\n", *(int *)arg, critical);
    SD_sleep();
    }
    printf("Out of loop\n");
    sem_post(&sema);
    
}
/*
thread no 4 =======> now sem_cnt-- sem_cnt == 3 ,
thread no 3 =======> now sem_cnt-- sem_cnt == 2 ,
thread no 2 =======> now sem_cnt-- sem_cnt == 1 ,
thread no 1 =======> now sem_cnt-- sem_cnt == 0 ,
*/
int main(int argc, char const *argv[])
{
    int i = 0, * a;
    //pthread_mutex_init(&mut_l, NULL);
    sem_init(&sema, 0, 15);//bin since the value is 1 || two range => 0 | 1
    while (i++ < 6)
    {
        a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i], NULL, &threader, a);
        //i++;
    }
    while (1)
    {        
    sem_wait(&sema);
    critical++;
    sem_post(&sema);
    SD_sleep();
    }  
    
    return 0;
}


/*
_SEMAPHORE - bin mutex
                counting different from mutex
sem_count = 2
critical sem_count-- = 1
    critical sem_count-- = 0

    ()
    sem_count
    
    cobination
        mutex - locking
            contion var - sem_count

*/