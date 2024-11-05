#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define DIM 1000
#define THREADS 4

int numeri[DIM];

typedef struct
{
    int inizio;
    int fine;
    int nRicercare;
    int trovato;
} ThreadData;

void *search(void *arg)
{
    ThreadData *data = (ThreadData *)arg;

    for (int i = data->inizio; i < data->fine; i++)
    {
        if (numeri[i] == data->nRicercare)
        {
            data->trovato = 1;
            break;
        }
    }
    pthread_exit(NULL);
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i < DIM; i++)
    {
        numeri[i] = rand() % 500 + 1;
    }
    int target;
    printf("Inserisci il numero da cercare: ");
    scanf("%d", &target);

    pthread_t threads[THREADS];
    ThreadData thread_data[THREADS];
    int step = DIM / THREADS;
    for (int i = 0; i < THREADS; i++)
    {
        thread_data[i].inizio = i * step;
        thread_data[i].fine = (i == THREADS - 1) ? DIM : (i + 1) * step; // assegno DIM se è l'ultimo thread, sennò (i+1)
        thread_data[i].nRicercare = target;
        thread_data[i].trovato = 0;
        pthread_create(&threads[i], NULL, search, (void *)&thread_data[i]);
    }

    int found = 0;
    for (int i = 0; i < THREADS; i++)
    {
        pthread_join(threads[i], NULL);
        if (thread_data[i].trovato)
        {
            printf("Il numero %d è alla posizione %d\n", target, thread_data[i].inizio);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Numero non trovato\n");
    }
}