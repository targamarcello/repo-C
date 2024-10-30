#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define  BUFFER_DIM 2048
int main()
{
    int scrivi, leggi;
    char messaggio[BUFFER_DIM];
    leggi=open("fifo1", O_RDONLY);
    while (1)
    {
        read(leggi, messaggio, sizeof(messaggio));
        printf("Processo 1: %s", messaggio);
        printf("Processo 2: ");
        fgets(messaggio, sizeof(messaggio),stdin);
        scrivi=open("fifo2", O_WRONLY);
        write(scrivi, messaggio, strlen(messaggio));
        close(scrivi);
    }
    return 0;
}