#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void sort(int count, char *strings[])
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(strings[j], strings[j + 1]) > 0)
            {
                // Scambia le stringhe
                char *temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv)
{

    if (argc != 2)
    {
        printf("ERRORE NEGLI ARGOMENTI!!!");
        exit(1);
    }
    sort(argc, argv);
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    for (int i = 2; i < argc; i++)
    {
        write(fd, argv[i], strlen(argv[i]));
        write(1, argv[i], strlen(argv[i]));
        write(1, argv[i], strlen(argv[i]));
        write(1, "\n", strlen("\n"));
    }
    close(fd);

    return 0;
}

/*Scrivere un programma in linguaggio C che legge da argv una serie di stringhe,
le ordina usando un algoritmo di ordinamento a scelta e scrive il risultato
sia a video che su un file il cui nome risiede in argv[1]. */