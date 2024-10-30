/*Progettare un algoritmo che effettui le seguenti operazioni:

• continui a leggere da tastiera una serie di terne di valori interi A ,
B e C finchè non vengono inseriti dei valori tali per cui A + B < C
• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
• prima di terminare, visualizzi il valore dei valori conteggiati*/

#include <stdio.h>
int main(int argc, char *argv[]){
    int num1,num2,num3, nPari=0, nDispari=0, nNull=0, differenza;
    do{
        printf("Inserisci num1\n");
        scanf("%d",&num1);
        printf("Inserisci num2\n");
        scanf("%d", &num2);
        printf("Inserisci num3\n");
        scanf("%d", &num3);
        differenza = num1-num2;
        if (differenza == 0)
		{
			nNull++;
		}

		if (differenza % 2 == 0)
		{
			nPari++;
		}
		else
		{
			nDispari++;
		}

    }while(num1+num2>num3);
    printf("I numeri pari sono: %d\n", nPari);
    printf("I numeri dispari sono: %d\n", nDispari);
    printf("I numeri nulli sono: %d\n", nNull);
    return 0;
}