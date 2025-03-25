#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Errore inserimento argomenti!!!");
        exit(1);
    }
    char stringa[1000], risPipe[1000];
    int p1p0[2], tot = 0;

    pipe(p1p0); //creazione pipe
    while (1)
    {
        printf("Quale parola vuoi cercare? ");
        scanf("%s", stringa);
        if (strcmp(stringa, "fine") == 0)
        {
            close(p1p0[1]);
            close(p1p0[0]);
            printf("Parole trovate: %d\n", tot);
            exit(0);
        }
        int pid = fork();
        if (pid == 0)
        {
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            execl("/usr/bin/grep", "grep", "-c", stringa, argv[1], (char *)0); //conteggio concorrenze
            return -1;
        }
        read(p1p0[0], risPipe, sizeof(risPipe));
        printf("Nel file ci sono %d %s\n", atoi(risPipe), stringa); //stampa a video numero concorrenze
        tot += atoi(risPipe);
    }
    return 0;
}

/*Si scriva un’applicazione concorrente che presenti la seguente interfaccia:

cercaStringhe FileIn

dove FileIn è un nome assoluto di file.

L’applicazione deve contare il numero di volte in cui un insieme di stringhe
che l’utente inserisce da terminale (una alla volta) compaiono all’interno
del file passato come parametro in argv[1].
Se in una riga del file una parola compare più volte, al fine del conteggio,
considerare solamente la prima occorrenza.
L’applicazione termina quando l’utente inserisce la stringa “fine”.
L’applicazione deve visualizzare il numero di volte in cui ogni stringa
compare nel file e anche, al termine dell’esecuzione, il numero totale di
stringhe trovate nel file.*/