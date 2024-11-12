/*Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero.*/

#include <stdio.h>

int main(int argc, char *argv[])
{

    int n1, n2;
    double ris;

    do
    {
        printf("Inserisci num1\n");
        scanf("%d", &n1);

        printf("Inserisci num2\n");
        scanf("%d", &n2);

        if (n1 > n2)
        {
            ris = (double)n2 / (double)n1;
        }
        else
        {
            ris = (double)n1 / (double)n2;
        }

    } while (n1 != 0 && n2 != 0);

    printf("Il risultato è: %.2f\n", ris);

    return 0;
}