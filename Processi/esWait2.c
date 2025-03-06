#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define VETTOR_SIZE 5

void calcolaSomma(int v[])
{
    int somma = 0;
    for (int i = 0; i < VETTOR_SIZE; i++)
    {
        somma += v[i];
    }
    printf("P1 mio PID=%d: la somma del vettore è %d\n", getpid(), somma);
}

void calcolaMinimo(int v[])
{
    int min = v[0];
    for (int i = 1; i < VETTOR_SIZE; i++)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
    }
    printf("P3 mio PID=%d: il valore minimo del vettore è %d\n", getpid(), min);
}

void calcolaMassimo(int v[])
{
    int max = v[0];
    for (int i = 1; i < VETTOR_SIZE; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    printf("P4 mio PID=%d: il valore massimo del vettore è %d\n", getpid(), max);
}

void calcolaMedia(int v[])
{
    int somma = 0;
    for (int i = 0; i < VETTOR_SIZE; i++)
    {
        somma += v[i];
    }
    float media = somma / (float)VETTOR_SIZE;
    printf("P5 mio PID=%d: la media del vettore è %.2f\n", getpid(), media);
}

int main()
{
    pid_t pid_p2, pid_p3, pid_p4, pid_p5;
    int v[VETTOR_SIZE];

    // Processo P1
    printf("P1 mio PID=%d: processo avviato\n", getpid());

    pid_p2 = fork(); // Crea P2

    if (pid_p2 == 0)
    {
        // Processo P2
        printf("P2 mio PID=%d: mio padre P1 ha PID=%d\n", getpid(), getppid());

        // P2 richiede input utente per il vettore
        printf("P2 mio PID=%d: inserisci 5 numeri interi:\n", getpid());
        for (int i = 0; i < VETTOR_SIZE; i++)
        {
            scanf("%d", &v[i]);
        }

        // P2 visualizza il contenuto del vettore
        printf("P2 mio PID=%d: il vettore è: ", getpid());
        for (int i = 0; i < VETTOR_SIZE; i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");

        // Calcola la somma, che viene visualizzata dal padre P1
        pid_p3 = fork(); // Crea P3
        if (pid_p3 == 0)
        {
            // Processo P3
            printf("P3 mio PID=%d: mio padre P2 ha PID=%d\n", getpid(), getppid());
            calcolaMinimo(v);
            exit(0);
        }
        else
        {
            waitpid(pid_p3, NULL, 0); // Aspetta che P3 finisca
        }

        // P2 visualizza il valore minimo
        printf("P2 mio PID=%d: atteso P3, valore minimo calcolato.\n", getpid());

        pid_p4 = fork(); // Crea P4
        if (pid_p4 == 0)
        {
            // Processo P4
            printf("P4 mio PID=%d: mio padre P2 ha PID=%d\n", getpid(), getppid());
            calcolaMassimo(v);
            exit(0);
        }
        else
        {
            waitpid(pid_p4, NULL, 0); // Aspetta che P4 finisca
        }

        // P2 visualizza il valore massimo
        printf("P2 mio PID=%d: atteso P4, valore massimo calcolato.\n", getpid());

        pid_p5 = fork(); // Crea P5
        if (pid_p5 == 0)
        {
            // Processo P5
            printf("P5 mio PID=%d: mio padre P2 ha PID=%d\n", getpid(), getppid());
            calcolaMedia(v);
            exit(0);
        }
        else
        {
            waitpid(pid_p5, NULL, 0); // Aspetta che P5 finisca
        }

        // P2 visualizza il valore medio
        printf("P2 mio PID=%d: atteso P5, valore medio calcolato.\n", getpid());
        exit(0);
    }
    else
    {
        // Processo P1 attende la terminazione di P2
        printf("P1 mio PID=%d: atteso P2\n", getpid());
        waitpid(pid_p2, NULL, 0);
        exit(0);
    }

    return 0;
}
/*Scrivi il codice
sorgente di un programma in cui


il processo padre P1



_ genera un processo
figlio P2


P2


_ genera un vettore v[
] di 5 numeri interi, forniti in input dall’utente >> N.B.
Fare attenzione!!!


_ visualizza il
contenuto del vettore


_ calcola la somma dei
numeri del vettore che, però, verrà visualizzata dal padre P1


_ successivamente,
genera il processo figlio P3


P3 calcola il valore
minimo tra i numeri del vettore


P2


_ attende la terminazione
di P3 e visualizza il valore minimo


_ successivamente,
genera il processo figlio P4


P4 calcola il valore
massimo tra i numeri del vettore


P2


_ attende la terminazione
di P4 e visualizza il valore massimo


_ successivamente,
genera il processo figlio P5


P5 calcola il valore medio
tra i numeri del vettore


P2


_ attende la terminazione
di P5 e visualizza il valore medio


\La prima cosa che
ciascun processo deve fare, appena genera un processo figlio, è dichiararsi nel
modo seguente:


"P1: mio PID=...,
mio figlio P2 ha PID=...


La prima cosa che
ciascun processo figlio deve fare appena è stato generato,


è dichiararsi nel modo
seguente:


"P2: mio PID=...,
mio padre P1 ha PID=..."





Ogni volta che un
processo visualizza qualcosa sullo schermo deve dichiararsi nel modo seguente:


"P1 mio PID=...:
quello che P1 deve visualizzare"


"Pn mio PID=...:
quello che Pn deve visualizzare"*/