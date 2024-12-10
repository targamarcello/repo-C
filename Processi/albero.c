#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int p2 = fork();
    if (p2 == 0) // P2
    {
        printf("Sono il figlio p2, PID: %d, mio padre è: %d\n", getpid(), getppid());
        int p4 = fork();
        if (p4 == 0)
        { // P4
            printf("Sono il figlio p4, PID: %d, mio padre è: %d\n", getpid(), getppid);
        }
        else if (p4 > 0)
        { // P2
            printf("Sono il figlio p2, PID: %d, mio padre è: %d\n", getpid(), getppid);
        }
        else
        { // ERRORE
            printf("Errore crezione del figlio");
        }
    }
    else if (p2 > 0) // P1
    {
        int p3 = fork();
        if (p3 == 0)
        { // P3
            printf("Sono il figlio p3, PID: %d,  mio padre è: %d\n", getpid(), getppid());
            int p5 = fork();
            if (p5 == 0)
            { // P5
                printf("Sono il figlio p5, PID: %d, mio padre è: %d\n", getpid(), getppid());
            }
            else if (p5 > 0) // P3
            {
                printf("Sono il figlio p3, PID: %d, mio padre è: %d\n", getpid(), getppid());
                int p6 = fork();
                if (p6 == 0)
                { // P6
                    printf("Sono il figlio p6, PID: %d, mio padre è: %d\n", getpid(), getppid());
                }
                else if (p6 > 0)
                { // P3
                    printf("Sono il figlio p3, PID: %d, mio padre è: %d\n", getpid(), getppid());
                }
                else
                {
                    printf("Errore creazione figlio");  
                }
            }
            else
            {
                printf("Errore creazione figlio");
            }
        }
        else if (p3 > 0)
        {
            printf("Sono il figlio p1, PID: %d\n", getpid());
        }
        else
        { // ERRORE
            printf("Errore crezione del figlio");
        }
    }
    else
    { // ERRORE
        printf("Errore creazione del figlio");
    }

    return 0;
}