#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *input, *pari, *dispari;
    int n;
    input = fopen("numeri.txt", "r");
    if (input == NULL)
    {
        printf("ERRORE APERTURA FILE INPUT!!");
        return 1;
    }

    pari = fopen("pari.txt", "w");
    if (pari == NULL)
    {
        printf("ERRORE APERTURA FILE NUMERI PARI!!");
        fclose(input);
        return 1;
    }
    dispari = fopen("dispari.txt", "w");
    if (dispari == NULL)
    {
        printf("ERROE APERTURA FILE NUMERI DISPARI!!");
        fclose(input);
        fclose(pari);
        return 1;
    }

    while (fscanf(input, "%d", &n) == 1)
    {
        if (n % 2 == 0)
        {
            fprintf(pari, "%d", n);
        }
        else
        {
            fprintf(dispari, "%d", n);
        }
    }
    fclose(input);
    fclose(pari);
    fclose(dispari);

    return 0;
}

/*Leggi il file numeri.txt già esistente, composto da una sequenza di numeri di una cifra separati da uno spazio.
Scrivi due file, pari.txt e dispari.txt
nei quali inserisci, rispettivamente, i numeri letti a seconda del loro valore pari o dispari.*/