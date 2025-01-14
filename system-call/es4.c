#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc < 5)
    {
        printf("ERRORE NELL'INSERIMENTO DEGLI ARGOMENTI!!!\n");
        exit(1);
    }
    int fd, cont = 0;
    char carattere, buffer[100];
    for (int i = 1; i < argc - 2; i++)
    {
        fd = open(argv[i], O_RDONLY);
        while (read(fd, &carattere, sizeof(carattere)) > 0)
        {
            if (carattere == argv[argc - 2][0])
            {
                cont++;
            }
        }
        close(fd);
    }
    sprintf(buffer, "Il carattere inserito %s compare %d volte nei file: %s %s %s\n", argv[argc - 2], cont, argv[1], argv[2], argv[3]);
    write(1, buffer, strlen(buffer));
    fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, buffer, strlen(buffer));
    close(fd);

    return 0;
}

/*Si vuole realizzare in linguaggio C un software monoprocesso che implementi il seguente comando:
$ cat file1.txt file2.txt file3.txt | grep “c”

Dove file[N].txt con N maggiore uguale a 1 sono una serie di files e il carattere "c" è a scopo esemplificativo e potrebbe essere
qualsiasi carattere.

Si utilizzino le system call al fine di leggere tutti i file di testo e, per ogni file, ricercare il carattere.
Al termine dell’esecuzione il software dovrà mostrare a video il numero di occorrenze del carattere trovate nei files e
dovrà contemporaneamente scrivere l’output su un file di testo il cui path sarà letto da argv.*/