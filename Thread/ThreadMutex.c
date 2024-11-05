#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define BUFFER_DIM 1024
#define BUFFER_SIZE 64

typedef struct
{
    unsigned char buffer[BUFFER_DIM];
    int n;
} BUFFER;

BUFFER ring_buffer[BUFFER_SIZE];
int eof = 0;
int read_index = 0;
int write_index = 0;
int N_Block = 0;

pthread_mutex_t mutex;
pthread_cond_t cond_read;
pthread_cond_t cond_write;

void *Leggi(void *arg)
{
    FILE *file = (FILE *)arg;
    int n;
    while (!feof(file))
    {
        pthread_mutex_lock(&mutex);
        while (N_Block >= BUFFER_SIZE)
        {
            pthread_cond_wait(&cond_write, &mutex);
        }
        n = fread(ring_buffer[write_index].buffer, 1, BUFFER_DIM, file);
        if (n > 0)
        {
            ring_buffer[write_index].n = n;
            write_index = (write_index + 1) % BUFFER_SIZE;
            N_Block++;
            pthread_cond_signal(&cond_read);
        }
        pthread_mutex_unlock(&mutex);
    }
    eof = 1;
}

void *Scrivi(void *arg)
{
    FILE *file = (FILE *)arg;
    while (!eof || N_Block > 0)
    {
        pthread_mutex_lock(&mutex);
        while (N_Block <= 0 && !eof)
        {
            pthread_cond_wait(&cond_read, &mutex);
        }
        if (N_Block > 0)
        {
            fwrite(ring_buffer[read_index].buffer, 1, ring_buffer[read_index].n, file);
            read_index = (read_index + 1) % BUFFER_SIZE;
            N_Block--;
            pthread_cond_signal(&cond_write);
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv[])
{
    FILE *origine, *destinazione;

    if (argc != 3)
    {
        printf("Non hai inserito tutti i file.");
        return 0;
    }

    origine = fopen(argv[1], "rb");

    if (origine == NULL)
    {
        printf("Il file di origine non si è aperto correttamente.");
        return 0;
    }

    destinazione = fopen(argv[2], "wb");

    if (destinazione == NULL)
    {
        printf("Il file di destinazione non si è aperto correttamente.");
        return 0;
    }

    pthread_t lettura, scrittura;

    pthread_create(&lettura, NULL, &Leggi, origine);
    pthread_create(&scrittura, NULL, &Scrivi, destinazione);
    pthread_join(lettura, NULL);
    pthread_join(scrittura, NULL);
    fclose(origine);
    fclose(destinazione);
    return 0;
}