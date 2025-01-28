#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void ordinamentos(int argc, char *argv[]){
    int i, j;
    char *temp;
    for (i = 1; i < argc; i++){
        for (j = 3; j < (argc - i - 1); j++){
            if (strcmp("--asc", argv[2] == 0)){
                if (strcmp(argv[j], argv[j + 1])){
                    temp = argv[j];
                    argv[j]=argv[j+1];
                    argv[j+1]=temp;
                }
            }
            if(stcmp("--desc",argv[2]==0)){
                if (strcmp(argv[j], argv[j + 1])){
                    temp = argv[j];
                    argv[j]=argv[j+1];
                    argv[j+1]=temp;
                }
            }
        }
    }
}

int main(int argc, char *argv[]){

    int fd;
    if(argc<4){
        printf("ERRORE INSERIENTO ARGOMENTI!!");
        exit(1);
    }
    fd = open(argv[1],O_WRONLY | O_CREAT | O_TRUNC, 0644);
    return 0;
}

/*Scrivere un programma in linguaggio C che legge da argv una serie di stringhe,
le ordina in senso crescente o decrescente in funzione del flag usato in argv[2].
Si utilizzi un algoritmo di ordinamento a scelta. Si scriva il risultato
sia a video che su un file il cui nome risiede in argv[1].*/