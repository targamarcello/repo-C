/*Creare un programma C dove il padre passa due variabili di tipo libro
 (STRUCT: titolo,autore e prezzo) al processo figlio che stampa i dati così ricevuti.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef struct 
{
    char titolo[50];
    char autore[50];
    float prezzo;
}Libro;
int main()
{
    int fd[2], p;
    if(pipe(fd)==-1)
    {
        printf("ERRORE PIPE!!");
        exit(-1);
    }
    p=fork();
    if(p==-1)
    {
        printf("ERRORE FORK!!!");
        exit(-1);
    }else if(p==0)//figlio
    {
        close(fd[1]);
        Libro l1, l2;
        read(fd[0], &l1, sizeof(Libro));
        read(fd[0], &l2, sizeof(Libro));
        printf("LIBRO 1:\n");
        printf("Titolo: %s", li.titolo);
        printf("Autore: %s", l1.autore);
        printf("Prezzo: %d", l1.prezzo);
        printf("LIBRO 2:\n");
        printf("Titolo: %s", l2.titolo);
        printf("Autore: %s", l2.autore);
        printf("Prezzo: %d", l2.prezzo);
        close(fd[0]);
    }else
    {
        close(fd[0]);
        Libro l1,l2;
        strcopy(l1.titolo, "Harry Potter");
        strcopy(l1.autore, "J. K. Rowling");
        l1.prezzo=800;
        strcopy(l2.titolo, "L'isola del tesoro");
        strcopy(l2.autore, "Robert Louis Stevenson");
        l2.prezzo=543;
        write(fd[1], &l1, sizeof(Libro));
        write(fd[1], &l2, sizeof(Libro));
        close(fd[1]);
        wait(NULL);
    }
    return 0;
} 