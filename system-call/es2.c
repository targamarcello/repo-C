#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERRORE ARGOMENTI!!");
        exit(1);
    }
    int fd;
    char alfabeto[] = "A - B - C - D - E - F - G - H - I - L - M - O - P - Q - R - S - T - U - V - W - X - Y - Z";
    fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    write(fd,alfabeto,strlen(alfabeto));
    close(fd);
    return 0;
}

/*Scrivere un programma in linguaggio C che scriva l'alfabeto su un file
il cui nome deve essere letto da argv[1]*/