// SERVER
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

#define DIM 1024
#define SERVERPORT 1313

int conta_parole(char str[])
{
    int conteggio = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
        {
            conteggio++;
        }
    }

    return conteggio;
}

int main()
{
    struct sockaddr_in servizio;
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM];
    char risposta[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 5);

    for (;;)
    {
        printf("\nServer in ascolto...\n");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&servizio, &fromlen);

        read(soa, str, sizeof(str));

        int parole = conta_parole(str);
        sprintf(risposta, "La frase è composta da %d parole", parole);

        write(soa, risposta, strlen(risposta));
        close(soa);
    }
    return 0;
}
