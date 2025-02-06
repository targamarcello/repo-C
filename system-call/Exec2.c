#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    if(argc<2){
        perror("ERRORE ARGOMENTI!!");
        exit(1);
    }
    execl("/usr/bin/cp","cp",argv[1],argv[2],NULL);
    
    return 0;
}
/*Scrivere un programma in linguaggio C che usa il comando 
della shell cp per copiare un file da una posizione 
sorgente ad una posizione destinazione

esempio:
$ ./a.out costituzione.txt /tmp/costituzione.txt*/