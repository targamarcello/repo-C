/*
Dato N un numero intero positivo, calcolare e visualizzare la
somma dei primi N numeri pari.
*/
#include <stdio.h>
int main(int argc, char *argv[])
{

    int N, somma = 0;

    printf("Inserisci N\n");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            somma = somma + i;
        }
    }
    printf("La somma dei primi N numeri pari è: %d", somma);

    return 0;
}
