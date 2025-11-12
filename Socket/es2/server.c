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

#define DIM 100
#define SERVERPORT 30000

int palindroma(char *str)
{
    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    struct sockaddr_in serv;
    int socketFD, soa, fromlen = sizeof(serv);
    char str[DIM], risposta[DIM];
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(SERVERPORT);
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketFD, (struct sockaddr *)&serv, sizeof(serv));
    listen(socketFD, 5);
    for (;;)
    {
        printf("\n\nServer in ascolto....");
        fflush(stdout);

        soa = accept(socketFD, (struct sockaddr *)&serv, &fromlen);
        read(soa, str, sizeof(str));
        printf("\nStringa ricevuta: %s", str);
        if (palindroma(str))
        {
            strcpy(risposta, "La stringa è palindroma");
        }
        else
        {
            strcpy(risposta, "La stringa non è palindroma");
        }
        write(soa, risposta, strlen(risposta));
        close(soa);
    }
    return 0;
}