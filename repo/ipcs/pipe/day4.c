#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<pthread.h>
    int pipefd[2];
    char buf;
int len = 0;
char *arr[7] = {"type","wait","stdi","stdl","unis","stri","pthr"};
void SD_sleep()
{
    for (size_t i = 0; i < 1000000; i++)
    {
        /* code */
    }
}
void *reader(void * args)
{
int *len = args, cur = 0;
while (1)
{
    printf("Hello\n");

    while (read(pipefd[0], &buf, 1) > 0)
    {
        write(STDOUT_FILENO, &buf, 1);
        cur++;
        if (cur == *len)
        {
            printf("\n");
            cur = 0;
        }
        
    }
        //write(STDOUT_FILENO, "\n", 1);
    SD_sleep();
    //close(pipefd[0]);
        //_exit(EXIT_SUCCESS);
}


}

int
main(int argc, char *argv[])
{
    pid_t cpid;
    pthread_t th;
    int i = 0;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    len = 4;//strlen(argv[1]);
    pthread_create(&th, NULL, &reader, (void*)&len);
    while(1) {            /* Parent writes argv[1] to pipe */
        //printf("Bye\n");
        //close(pipefd[0]);          /* Close unused read end */
        write(pipefd[1], arr[i++], len);
        if (i > 6)
        {
            i = 0;
        }
        
    //pthread_cond_signal(&cond_lock);
    SD_sleep();
        //close(pipefd[1]);          /* Reader will see EOF */
        //printf("Bye\n");
        //wait(NULL);                /* Wait for child */
        //exit(EXIT_SUCCESS);
    }
}