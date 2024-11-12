/*
Dato un numero N calcolare e visualizzare tutte le coppie di numeri minori di N che
danno per somma il numero stesso. Non considerare la proprietà commutativa. 
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int N;
    printf("Inserisci N\n");
    scanf("%d", &N);

    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            if (i + j == N)
            {
                printf("La somma tra %d e %d fa %d\n", i, j, N);
            }
        }
    }

    return 0;
}
