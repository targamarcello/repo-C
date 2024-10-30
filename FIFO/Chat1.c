#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_DIM 2048
int main()
{
    int scrivi, leggi;
    char messaggio[BUFFER_DIM];
    leggi=open("fifo2", O_RDONLY);
    while (1)
    {
        printf("Processo 1: ");
        fgets(messaggio,sizeof(messaggio),stdin);
        scrivi=open("fifo1", O_WRONLY);
        write(scrivi,messaggio,strlen(messaggio));
        close(scrivi);

        read(leggi, messaggio,sizeof(messaggio));
        printf("Processo 2: %s", messaggio);
    }

    return 0;
}