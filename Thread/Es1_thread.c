#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct
{
    char nome[20];
    char cognome[20];
    char classe[20];
    float media;
} Studente;

void *stampaV(void *arg)
{
    Studente *stud = (Studente *)arg;
    printf("Dati Video\n");
    printf("Nome: %s\n", stud->nome);
    printf("Cognome: %s\n", stud->cognome);
    printf("Classe: %s\n", stud->classe);
    printf("Media: %2f\n", stud->media);
}

void *stampaF(void *arg)
{
    Studente *stud = (Studente *)arg;
    FILE *file = fopen("dati_stud.txt", "w");
    if (file == NULL)
    {
        perror("ERRORE CREAZIONE FILE\n");
        exit(-1);
    }
    fprintf(file, "Dati File:\n");
    fprintf(file, "Nome: %s\n", stud->nome);
    fprintf(file, "Cognome: %s\n", stud->cognome);
    fprintf(file, "Classe: %s\n", stud->classe);
    fprintf(file, "Media: %.2f\n", stud->media);
    fclose(file);
}

int main()
{
    Studente stud;
    printf("Inserisci nome studente:\n");
    scanf("%s", stud.nome);
    printf("Inserisci cognome studente:\n");
    scanf("%s", stud.cognome);
    printf("Inserisci classe studente:\n");
    scanf("%s", stud.classe);
    printf("Inserisci media studente:\n");
    scanf("%f", &stud.media);
    pthread_t thread1, thread2;
    if (pthread_create(&thread1, NULL, stampaV, (void *)&stud) != 0)
    {
        perror("ERRORE CREAZIONE THREAD 1\n");
        exit(-1);
    }
    if (pthread_create(&thread2, NULL, stampaF, (void *)&stud) != 0)
    {
        perror("ERRORE CREAZIONE THREAD 2\n");
        exit(-1);
    }
    if (pthread_join(thread1, NULL) != 0)
    {
        perror("ERRORE THREAD 1 \n");
        exit(-1);
    }
    if (pthread_join(thread2, NULL) != 0)
    {
        perror("ERRORE THREAD 2\n");
        exit(-1);
    }
}