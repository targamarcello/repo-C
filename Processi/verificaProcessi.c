#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 5

int main(int argc, char *argv[])
{
    pid_t p2, p3;
    int numeri[SIZE], somma = 0;
    float media = 0;
    printf("P1: mio PID = %d, mio figlio P2 ha PID = %d,P3 ha PID = %d\n", getpid(), p2, p3);
    for (int i = 0; i < SIZE; i++)
    {
        numeri[i] = rand() % 10 + 1;
        printf("%d ", numeri[i]);
    }
    printf("\n");

    p2 = fork();
    if (p2 == 0)
    {
        printf("P2: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());
        int p4 = fork();
        if (p4 == 0)
        {
            printf("P4: mio PID = %d, mio padre P2 ha PID = %d\n", getpid(), getppid());
            for (int i = 0; i < SIZE; i++)
            {
                somma += numeri[i];
            }
            printf("P4: %d\n", somma);
            exit(0);
        }
        else
        {
            wait(NULL);
            exit(0);
        }
    }
    else
    {
        p3 = fork();
        if (p3 == 0)
        {
            printf("P3: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());
            int p5 = fork();
            if (p5 == 0)
            {
                printf("P5: mio PID = %d, mio padre P3 ha PID = %d\n", getpid(), getppid());
                for (int i = 0; i < SIZE; i++)
                {
                    media += numeri[i];
                }
                media /= SIZE;
                printf("P5: %.2f\n", media);
                exit(0);
            }
            else
            {
                wait(NULL);
                exit(0);
            }
        }
        else
        {
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}