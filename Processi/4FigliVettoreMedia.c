/*Scrivi il codice sorgente di un prg in cui:
_ il processo PADRE
_visualizza il proprio PID
_genera 4 figli: F1, F2, F3, F4
_ genera 2 numeri interi random, n1, n2
 compresi tra 1 e 20
necessariamente diversi tra loro
_visualizza n1 ed n2:
  a prescindere dal valore di n1 ed n2, 
  F2 dovrà dormire per un numero di secondi pari a n1 e
  restituire al padre un numero n2_dim intero compreso tra 2 e 6 estremi compresi;
  F3  dovrà dormire per un numero di secondi pari a n2 e
  restituire al padre un numero n3_dim intero compreso tra 2 e 10 estremi inclusi;
  non si sa chi dormirà di meno o di più ossia
  non si sa chi tra F2 ed F3 terminerà per primo.
_ solo dopo avere generato entrambi (sia F2 e sia F3),
   attende la loro terminazione:
il numero intero restituito da F2 rappresenterà la dimensione dim  del vettore che F1 dovrà generare
_per ciascun figlio, il padre visualizza il proprio PID e il PID del proprio figlio

CIASCUN FIGLIO deve:
identificrsi dicendo se è F1 o F2 o F3 o F4
_ visualizzare il proprio PID e il PID del proprio padre

F1 deve:
_ generare il vettore v[ ] di numeri interi di dimensione dim fornito in ingresso dall'utente e compresi tra 1 e 10 estremi inclusi
_ calcolarne la somma (somma)

F4 deve:
_ calcolare il valore medio (media) dei numeri  fornito in ingresso dall'utente e memorizzati nel vettore e
_ restituirlo al padre

Il PADRE deve:
visualizzare il proprio PID e il valore restituitogli da F4 
con un chiaro messaggio in cui precisa ciò che esso rappresenta:
"Sono il padre, il mio PID = ... , il valore medio dei numeri con cui hai popolato il vettore vale ..."*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_VETTORE 10

// Funzione per generare numeri casuali
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Funzione che calcola la somma degli elementi di un vettore
int somma_vettore(int v[], int dim) {
    int somma = 0;
    for (int i = 0; i < dim; i++) {
        somma += v[i];
    }
    return somma;
}

// Funzione che calcola la media degli elementi di un vettore
float media_vettore(int v[], int dim) {
    int somma = somma_vettore(v, dim);
    return (float)somma / dim;
}

int main() {
    srand(time(NULL)); // Inizializza il generatore di numeri casuali

    pid_t pid_f1, pid_f2, pid_f3, pid_f4;
    int n1, n2;
    int n2_dim, n3_dim;
    int vettore[MAX_VETTORE];

    // Processo padre: visualizza il proprio PID
    printf("Sono il padre, il mio PID = %d\n", getpid());

    // Generazione di 2 numeri casuali diversi tra loro
    do {
        n1 = random_int(1, 20);
        n2 = random_int(1, 20);
    } while (n1 == n2);

    printf("Il numero n1 generato è: %d\n", n1);
    printf("Il numero n2 generato è: %d\n", n2);

    // Creazione dei figli
    pid_f2 = fork();
    if (pid_f2 == 0) { // Processo figlio F2
        printf("Sono F2, il mio PID = %d, il PID del padre = %d\n", getpid(), getppid());
        sleep(n1); 
        n2_dim = random_int(2, 6); 
        printf("F2 restituisce il numero n2_dim = %d\n", n2_dim);
        exit(n2_dim); 
    }

    pid_f3 = fork();
    if (pid_f3 == 0) { // Processo figlio F3
        printf("Sono F3, il mio PID = %d, il PID del padre = %d\n", getpid(), getppid());
        sleep(n2); 
        n3_dim = random_int(2, 10); 
        printf("F3 restituisce il numero n3_dim = %d\n", n3_dim);
        exit(n3_dim);
    }

    pid_f1 = fork();
    if (pid_f1 == 0) { // Processo figlio F1
        printf("Sono F1, il mio PID = %d, il PID del padre = %d\n", getpid(), getppid());
        int status_f2, status_f3;
        waitpid(pid_f2, &status_f2, 0);
        waitpid(pid_f3, &status_f3, 0);

        n2_dim = WEXITSTATUS(status_f2);

        printf("F1 riceve la dimensione del vettore da F2: %d\n", n2_dim);

        for (int i = 0; i < n2_dim; i++) {
            vettore[i] = random_int(1, 10);
        }

        // Calcolare la somma del vettore
        int somma = somma_vettore(vettore, n2_dim);
        printf("La somma del vettore è: %d\n", somma);

        exit(somma);
    }

    pid_f4 = fork();
    if (pid_f4 == 0) { // Processo figlio F4
        printf("Sono F4, il mio PID = %d, il PID del padre = %d\n", getpid(), getppid());
        int status_f1;
        waitpid(pid_f1, &status_f1, 0);

        // Calcolare la media del vettore (vettore passato da F1)
        float media = media_vettore(vettore, n2_dim);
        printf("F4 restituisce il valore medio: %.2f\n", media);
        exit((int)(media * 100));

    // Processo padre: attende la terminazione dei figli F1 e F4
    int status_f1, status_f4;
    waitpid(pid_f1, &status_f1, 0);
    waitpid(pid_f4, &status_f4, 0);

    // Ottenere i risultati dai figli F1 e F4
    int somma_f1 = WEXITSTATUS(status_f1);
    float media_f4 = (float)WEXITSTATUS(status_f4) / 100;

    printf("Sono il padre, il mio PID = %d, il valore medio dei numeri con cui hai popolato il vettore vale %.2f\n", getpid(), media_f4);

    return 0;
}
