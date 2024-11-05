#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int p, status, num[3], somma, prodotto;
    for (int i = 0; i < 3; i++)
    {
        printf("Inserisci numero\n");
        scanf("%d", &num[i]);
    }
    p = fork();
    if (p < 0)
    {
        printf("Errore fork");
        exit(-1);
    }
    else if (p > 0) // padre
    {
        printf("Sono il daddy e il mio PID è: %d\n", getpid());
        wait(&status);
        somma = WEXITSTATUS(status);
        prodotto = num[2] * somma;
    }
    else // figlio
    {
        printf("\nSono il baby-daddy e il mio PID è: %d\n", p);
        somma = num[0] + num[1];
        exit(somma);
    }
    printf("La somma è: %d\n Il prodotto è: %d", somma, prodotto);
    return 0;
}