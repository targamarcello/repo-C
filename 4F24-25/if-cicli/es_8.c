/*Progettare un algoritmo che risolve il seguente problema. Si desidera 
calcolare la somma delle radici quadrate di N valori numerici inseriti 
dall’utente, con N inserito in input. 
L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
con un messaggio di errore quando viene inserito un numero che non
permette di effettuare il calcolo (nel dominio dei numeri reali).*/

#include <stdio.h>
#include <math.h>
int main (int argc, char *argv[]){
    int num1, num2;
    double radice;
    do{
        printf("Inserisci num1\n");
        scanf("%d",&num1);
        printf("Inserisci num2\n");
        scanf("%d",&num2);

        if(num1>num2){
            radice= sqrt(num1/num2);
            if(radice>0){
                printf("VALORI FUORI DOMINIO!!!\n");
                return 0;
            }else{
                radice = sqrt(num2/num1);
                if(radice<=0){
                    printf("VALORI FUORI DOMINIO!!!\n");
                    return 0;
                }
            }
        }
        printf("Radice quadrata del rapporto: %.2f\n",radice);

    }while(1);
       
    return 0;
}