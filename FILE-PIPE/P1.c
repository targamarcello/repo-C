#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

struct Student
{
    char nome[50];
    char cognome[50];
    int eta;
};

int main()
{
    int p;
    struct Student studente;
    char eta_str[10];

    printf("Inserisci il nome dello studente: ");
    scanf("%s", studente.nome);
    printf("Inserisci il cognome dello studente: ");
    scanf("%s", studente.cognome);
    printf("Inserisci l'età dello studente: ");
    scanf("%d", &studente.eta);

    sprintf(eta_str, "%d", studente.eta);

    // Creazione di P1
    p = fork();
    if (p == 0)
    {
        // Passiamo il nome, cognome e l'età come stringhe
        execl("./processo_P2", "processo_P2", studente.nome, studente.cognome, eta_str, NULL);
        perror("Errore nell'esecuzione di execl");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Processo P2 termina le sue funzioni
        wait(NULL);
        printf("Processo P2 terminato\n");
    }

    return 0;
}