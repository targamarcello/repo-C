#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define DIM 3

int main(int argc, char *argv[])
{

    // Dichiarazione delle variabili
    pid_t p2, p3, p4, p5, p6;
    int arr[DIM];

    printf("P1 %d", getpid()); // main si dichiara

    srand(time(NULL));
    for (int i = 0; i < DIM; i++)
    {
        arr[i] = rand() % 6;
    }

    p2 = fork();
    if (p2 > 0) // P1
    {
        p3 = fork();
        if (p3 > 0) // P1
        {
        }
        else if (p3 == 0) // P3
        {
            p6 = fork();
            if (p6 > 0) // P3
            {
            }
            else if (p6 == 0) // P6
            {
            }
            else
                printf("Errore generazione del figlio!");
        }
    }
    else if (p2 == 0) // P2
    {
        p4 = fork();
        if (p4 > 0) // P2
        {
            p5 = fork();
            if (p5 > 0) // P4
            {
            }
            else if (p5 == 0) // P5
            {
            }
            else
                printf("Errore generazione del figlio!");
        }
        else if (p4 == 0) // P4
        {
        }
        else
            printf("Errore generazione del figlio!");
    }
    else // p2 < 0
    {
        printf("Errore generazione del figlio!");
    }

    return 0;
}