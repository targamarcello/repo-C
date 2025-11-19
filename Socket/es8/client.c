/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER in cui il server riceve in input una stringa e,
 dopo aver effettuato gli opportuni controlli (se necessari), rispedisce al client il numero totale di parole presenti nella stringa.*/
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

#define DIM 1024
#define SERVERPORT 1313

int main(int argc, char **argv)
{
    struct sockaddr_in servizio;
    char str1[DIM],buffer[DIM];
    int socketfd,conteggio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    printf("Inserisci la stringa\n");
    fgets(str1,sizeof(str1),stdin);

    write(socketfd, str1, sizeof(str1));
    read(socketfd,buffer,DIM);
    printf("Risultato: \n%s",buffer);

    close(socketfd);
    return 0;
}
