/*Progettare un algoritmo che effettui le seguenti operazioni:
• legga da tastiera una coppia di valori interi A e B con A<B;
• continui a leggere da tastiera una serie di valori interi, terminando 
quando il valore letto è al di fuori dell’intervallo [A, B];
• conteggi la media dei valori letti;
• prima di terminare, stampi il valore calcolato.*/

#include <stdio.h>
int main(int argc, char *argv[]){
    int num1, num2, somma=0,n,i=0;
    double media;
    do{
        printf("Inserisci num1\n");
        scanf("%d", &num1);
        printf("Inserisci num2\n");
        scanf("%d", &num2);
    }while(num2<num1);

    do{
        printf("Inserisci un numero a caso\n");
        scanf("%d", &n);
        if(n>=num1 && n <=num2){
            somma = somma +n;
            i++;
        }
    }while(n>=num1 && n <=num2);
    media = (double)somma / (double)i;
    printf("La media è: %f", media);

    return 0;
}