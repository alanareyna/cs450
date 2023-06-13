#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

void *doWork(void *vargp) 
{ 
    sleep(1); 
    printf("I am a thread\n");
    return NULL; 
}

void *doSomethingElse(void *vargp)
{
    sleep(4);
    printf("I am a thread that likes more sleep \n");
    return NULL;
}
   
int main() 
{
    pthread_t t1, t2, t3, t4;

    printf("Before Thread\n");

    pthread_create(&t1, NULL, doWork, NULL);
    pthread_create(&t2, NULL, doWork, NULL);
    pthread_create(&t3, NULL, doSomethingElse, NULL);
    pthread_create(&t4, NULL, doSomethingElse, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    printf("After Thread\n");

    exit(0); 
}
