#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

#define DIM 512
#define SERVERPORT 1313

/*
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e un carattere,e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il
numero di occorrenze del carattere nella stringa.
*/

int main()
{
    int socketTrasporto;
    struct sockaddr_in indirizzo_remoto;
    char stringa[DIM], risposta[DIM];
    char carattere;
    socketTrasporto = socket(AF_INET, SOCK_STREAM, 0);

    indirizzo_remoto.sin_family = AF_INET;
    indirizzo_remoto.sin_port = htons(SERVERPORT);

    connect(socketTrasporto, (struct sockaddr *)&indirizzo_remoto, sizeof(indirizzo_remoto));

    printf("Inserisci una stringa: ");
    scanf("%s", stringa);
    printf("Inserisci il carattere");
    scanf("%c", &carattere);
    write(socketTrasporto, stringa, strlen(stringa));
    write(socketTrasporto, &carattere, strlen(&carattere));
    read(socketTrasporto, risposta, sizeof(risposta));

    printf("Risposta ricevuta dal server: %s\n", risposta);

    close(socketTrasporto);
    return 0;
}