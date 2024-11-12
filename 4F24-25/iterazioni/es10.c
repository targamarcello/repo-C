/*
Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.
*/
#include <stdio.h>
int main(int argc, char *argv[])
{

    int N, somma = 0;

    printf("Inserisci N\n");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        somma = somma + i;
    }
    printf("La somma dei primi N è: %d", somma);
    return 0;
}
