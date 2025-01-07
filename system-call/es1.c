#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER 8
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore numero argomenti!!!");
        exit(1);
    }

    int fd, charRead;
    char buff[BUFFER];
    fd = open(argv[1], O_RDONLY);
    while ((charRead = read(fd, buff, sizeof(buff))) > 0)
    {
        write(1, buff, charRead);
    }
    close(fd);
    return 0;
}