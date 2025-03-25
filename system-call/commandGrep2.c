#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]){
    
    if (argc != 2)
    {
        printf("Errore inserimento argomenti!!!");
        exit(1);
    }
    char stringa[1000], risPipe[1000];
    int p1p2[2],p2p0[2], tot = 0,pid;
    while (1)
    {
        printf("Quale parola vuoi cercare? ");
        scanf("%s",stringa);
        if(strcmp(stringa,"fine")==0){
            printf("Parole trovate: %d\n",tot);
            exit(0);
        }
        pipe(p1p2);
        pid = fork();
        if(pid == 0){
            close(p1p2[0]);
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);
            execl("/usr/bin/grep","grep","-ow",stringa,argv[1],(char *)0);
            return -1;
        }

        pipe(p2p0);
        pid = fork();
        if(pid == 0){
            close(p1p2[1]);
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            close(p2p0[0]);
            close(1);
            dup(p2p0[1]);
            close(p2p0[1]);
            execl("/usr/bin/wc","wc","-l",(char *)0);
            return -1;
        }
        close(p1p2[0]);
        close(p1p2[1]);
        close(p2p0[1]);
        read(p2p0[0],risPipe,sizeof(risPipe));
        close(p2p0[0]);
        printf("Nel file ci sono %d %s\n", atoi(risPipe), stringa);
        tot += atoi(risPipe);
    }
    
    
    
    return 0;
}




/*Si scriva un’applicazione concorrente che presenti la seguente interfaccia:

cercaStringhe FileIn.txt

dove FileIn.txt è un nome assoluto di file.

L’applicazione deve contare il numero di volte in cui un insieme di stringhe
che l’utente inserisce da terminale (una alla volta) compaiono all’interno
del file passato come parametro in argv[1].
L’applicazione termina quando l’utente inserisce la stringa “fine”.

L’applicazione deve visualizzare il numero di volte in cui ogni stringa
compare nel file e anche, al termine dell’esecuzione, il numero totale di
stringhe trovate nel file.

L'applicazione dovrà tenere conto dell'eventuale molteplicità di una parola
dentro alla stessa stringa, per fare questo si consiglia di invocare grep
con il flag -ow e redirezionare il suo output in wc (invocato con il flag -l).*/