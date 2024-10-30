#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM 100
#define nThread 4
int array[NUM];
int trovato = 0;
typedef struct
{
    int first;
    int last;
} ElementiThread;

void *cercaNum(void *arg)
{
    ElementiThread *args = (ElementiThread *)arg;
    for (int i = args->first; i < args->last; i++)
    {
        if (array[i] == 8 && !trovato)
        {
            printf("numero 8 trovato in posizione: %d\n", i);
            trovato = 1;
        }
    }
    pthread_exit(NULL);
}

int main()
{
    for (int i = 0; i < NUM; i++)
    {
        if (i == 8)
            array[i] = 8;
        else
            array[i] = rand() % 10;
    }
    pthread_t threads[nThread];
    ElementiThread args[nThread];
    int iniziando = NUM / nThread;
    int concludando = NUM % nThread;
    int index = 0;
    for (int i = 0; i < nThread; i++)
    {
        args[i].first = index;
        index += iniziando;
        if (concludando > 0)
        {
            index++;
            concludando--;
        }
        args[i].last = index;
        pthread_create(&threads[i], NULL, &cercaNum, (void *)&args[i]);
    }
    for (int i = 0; i < nThread; i++)
    {
        pthread_join(threads[i], NULL);
    }
}