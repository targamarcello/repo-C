#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int agrc, char *argv[])
{
    int p;

    p = fork();
    if (p > 0){ // padre
        for(int i=0; i<=19; i++){
            printf("Sono il padre e il mio conto è a %d\n",i);
        }    
    }
    else if (p == 0){ // figlio
        for(int j=0; j<=9; j++){
            printf("Sono il figlio e il mio conto è a %d\n",j);
        }
    }
    else{
        printf("ERRORE!!");
        exit(-1);
    }
    return 0;
}

/*Scrivi il codice sorgente di un programma che permette al processo padre di generare un processo figlio:
_ sia padre che figlio visualizzano il proprio PID e il PID del proprio parente
_ padre conta da 0 a 19
_ figlio conta da 0 a 9.*/