#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM 100
#define nThread 4
int arrayNum[NUM];
int trovato = 0;

void *cercaNum(void *arg)
{
    int first = *((int *)arg);
    int last = first + NUM / 2;
    for (int i = 0; i < last; i++)
    {
        if (arrayNum[i] == 8)
        {
            printf("numero 8 trovato in posizione %d\n", i);
            trovato = 1;
        }
    }
}

int main()
{
    int pos8 = rand() % NUM;
    for (int i = 0; i < NUM; i++)
    {
        if (i == pos8)
        {
            arrayNum[i] = 8;
        }
        else
        {
            arrayNum[i] = rand() % 10;
        }
    }
    pthread_t thread[nThread];
    int startIndex[nThread] = {0, NUM / 2};
    for (int i = 0; i < nThread; i++)
    {
        if (pthread_create(&thread[i], NULL, &cercaNum, &startIndex[i]) != 0)
        {
            perror("ERRORE CREAZIONE THREAD\n");
            exit(-1);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (pthread_join(thread[i], NULL) != 0)
        {
            perror("ERRORE THREAD\n");
            exit(-1);
        }
    }
    if (!trovato)
    {
        printf("numero 8 non trovato");
    }
}