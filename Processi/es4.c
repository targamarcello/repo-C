#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int ricercaPos(int arrayNum[], int lunghezza, int num){
    for(int i=0; i<lunghezza; i++){
        if(arrayNum[i]==num){
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[]){
    int arrayNumeri[] = {1,2,3,4,5,6,7,8,9,0};
    int index = atoi(argv[1]);
    int p = fork();
    if(p==0){
        int pos = ricercaPos(arrayNumeri, 10, index);
        if(pos>-1){
            printf("Il numero %d è presente in posizione %d\n",index,pos);
        }else{
            printf("Numero non trovato!!\n");
            exit(1);
        }
    }
    wait(&p);
    return 0;
}
/*Scriva un programma C che dato un array prestabilito, prenda in input da
riga di comando un numero e lo ricerchi all'interno dell'array.
La ricerca deve essere demandata ad un processo figlio e deve essere
implementata attraverso un'apposita funzione di nome ricerca.*/