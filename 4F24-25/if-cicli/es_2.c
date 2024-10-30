/*Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
• per ogni coppia di numeri letti:
◦ calcoli il prodotto dei due numeri e ne stampi il valore
◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
• all’uscita del ciclo, stampi il valore della somma*/

#include <stdio.h>

int main(int argc, char *argv[]){

    int num1,num2, prod, somma=0;

    do{
        printf("Inserisci num1\n");
        scanf("%d", &num1);
        printf("Inserisci num2\n");
        scanf("%d", &num2);
        prod = num1*num2;
        printf("Prodotto dei numeri è: %d\n", prodotto);

        somma = somma + prod;
    }while(num1!=0 && num2!=0);

    printf("Somma dei numeri: %d\n", somma);

    return 0;
}