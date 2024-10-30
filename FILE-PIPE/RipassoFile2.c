#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char *argv)
{
    char stringa[100];
    /*FILE *lettura;
    lettura=fopen("file scrittura", "r");
    fgets(stringa, 100, lettura);           ES FILE
    printf("la stringa letta è: %s\n", stringa);
    fclose(lettura);*/

    /*int fd=open("fifo1", O_RDONLY);
    read(fd,&stringa, sizeof(stringa));         ES FIFO
    printf("la stringa è: %s\n", stringa);
    close(fd);*/
    return 0;
}