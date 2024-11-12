/*
Dato N un numero intero positivo, generare e visualizzare in ordine
decrescente i primi N numeri interi positivi.
*/
#include <stdio.h>
int main(int argc, char *argv[])
{

    int N;
    printf("Inserisci N\n");
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        printf("%d", i);
    }

    return 0;
}
