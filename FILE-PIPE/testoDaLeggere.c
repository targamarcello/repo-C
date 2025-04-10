#include <stdio.h>
#include <stdlib.h>

#define FILENAME 50

int main(int argc, char *argv[])
{

    char fileSorgente[FILENAME];
    char fileDestinazione[FILENAME];
    char c;
    FILE *src, *dest;

    printf("Inserire nome file sorgente \n");
    scanf("%s", fileSorgente);
    printf("Inserire file destinazione \n");
    scanf("%s", fileDestinazione);

    src = fopen(fileSorgente, "r");
    if (src == NULL)
    {
        printf("ERRORE APERTURA FILE SORGENTE!!");
        return 1;
    }
    dest = fopen(fileDestinazione, "w");
    if (dest == NULL)
    {
        printf("ERRORE APERTURA FILE DESTINAZIONE!!");
        return 1;
    }

    while ((c = fgetc(src)) != EOF)
    {
        fputc(c, dest);
    }
    fclose(src);
    fclose(dest);

    return 0;
}

/*Scrivi il
codice sorgente di un prg che


Copia,
carattere per carattere, il contenuto di un file già esistente


In un
secondo file da creare.


I nomi dei
file devono essere forniti in input dall’utente da tastiera

Obiettivo: usa re vettori, puntatori, file*/