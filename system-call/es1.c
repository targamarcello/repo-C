#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if(argc!=2){
        printf("Errore numero argomenti!!!");
        exit(1);
    }

    int fd, charRead;
    char buff;
    fd = open(argv[1], O_RDONLY);
    while (charRead = read(fd, &buff,sizeof(buff))>0)
    {
        write(1,&buff,charRead);
    }
    close(fd);
    return 0;
}
/*Utilizzando le system call open, read, write, close leggere il file rfc1918.txt e stamparlo a video.
Il programa deve essere cosi invocato:
$./a.out rfc1918.txt

Consiglio: leggere un carratere per volta */