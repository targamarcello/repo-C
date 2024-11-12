/*
Dato un numero intero positivo N verificare se N è un numero primo.
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int N;
    printf("Inserisci N\n");
    scanf("%d", &N);
    for (int i = N - 1; i > 1; i--)
    {
        if (N % i == 0)
        {
            printf("IL NUMERO NON è PRIMO!!!");
        }
    }
    printf("IL NUMERO è PRIMO");

    return 0;
}
