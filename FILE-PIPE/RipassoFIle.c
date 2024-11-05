#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char *argv)
{
    char stringa[] = "RIPASSO FILE";
    // FILE *scrittura;
    // scrittura= fopen("file scrittura", "w");      ES FILE
    // fprintf(scrittura, "%s",stringa);
    // fclose(scrittura);

    /*mkfifo("fifo1",0777);
    int fd = open("fifo1", O_WRONLY);
    write(fd,&stringa,sizeof(stringa));   ES FIFO
    close(fd);
    printf("Scrittura conclusa\n");*/
    return 0;
}