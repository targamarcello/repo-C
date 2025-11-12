/*Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client 2 stringhe; la
prima composta dalle lettere di posizione pari e la seconda composta dalle lettere di posizione dispari.*/
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 50
#define SERVERPORT 1313

int main(int argc, char **argv)
{
    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    char str1[DIM], strPari[DIM], strDispari[DIM];
    int socketfd;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    printf("Inserisci la stringa\n");
    scanf("%s", str1);

    write(socketfd, str1, sizeof(str1));

    read(socketfd, strPari, sizeof(strPari));
    read(socketfd, strDispari, sizeof(strDispari));

    close(socketfd);
    return 0;
}