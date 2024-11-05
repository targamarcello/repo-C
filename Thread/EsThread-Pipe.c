#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_DIM 1024

void *LeggiFile(void *arg)
{
    int *fd = (int *)arg;
    FILE *origine = fopen("Lettura.txt", "r");
    if (origine == NULL)
    {
        printf("Errore apertura file di origine");
        pthread_exit(NULL);
    }
    char buffer[BUFFER_DIM];
    int lettura;
    while (lettura = fread(buffer, 1, BUFFER_DIM, origine) > 0)
    {
        write(*fd, buffer, lettura);
    }
    fclose(origine);
    close(*fd);
    pthread_exit(NULL);
}
void *ScriviFile(void *arg)
{
    int *fd = (int *)arg;
    FILE *destinazione = fopen("Scrittura.txt", "w");
    if (destinazione == NULL)
    {
        printf("Errore apertura file di destinazione");
        pthread_exit(NULL);
    }
    char buffer[BUFFER_DIM];
    int scrittura;
    while (scrittura = read(*fd, buffer, BUFFER_DIM) > 0)
    {
        fwrite(buffer, 1, scrittura, destinazione);
    }
    fclose(destinazione);
    close(*fd);
    pthread_exit(NULL);
}
int main()
{
    char nomeOrigine[50];
    char nomeDestinazione[50];
    printf("Inserisci nome file di origine: \n");
    scanf("%s", nomeOrigine);
    printf("Inserisci nome file di destinazione: \n");
    scanf("%s", nomeDestinazione);
    FILE *org = fopen(nomeOrigine, "r");
    FILE *dest = fopen(nomeDestinazione, "w");
    int fd[2];
    if (pipe(fd) == -1)
    {
        printf("errore creazione pipe\n");
        exit(-1);
    }
    pthread_t lettura, scrittura;
    pthread_create(&lettura, NULL, &LeggiFile, (void *)&fd[0]);
    pthread_create(&scrittura, NULL, &ScriviFile, (void *)&fd[1]);
    pthread_join(lettura, NULL);
    pthread_join(scrittura, NULL);
    fclose(org);
    fclose(dest);
    printf("PROGRAMMA FINITO\n");
}