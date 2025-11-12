/*Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il messaggio se
è palindroma oppure non lo è.*/

// CLIENT
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 100
#define SERVERPORT 30000

int main(int argc, char *argv[])
{
    struct sockaddr_in serv;
    int socketFD;
    char str[DIM], risposta[DIM];

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(SERVERPORT);
    socketFD = socket(AF_INET, SOCK_STREAM, 0);

    connect(socketFD, (struct sockaddr *)&serv, sizeof(serv));
    printf("Inserisci una stringa: ");
    scanf("%s", str);

    write(socketFD, str, sizeof(str));
    read(socketFD, risposta, sizeof(risposta));

    printf("Risposta server: %s\n", risposta);
    close(socketFD);

    return 0;
}