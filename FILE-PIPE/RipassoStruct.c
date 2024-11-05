#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    typedef struct
    {
        char titolo[20];
        char autore[20];
        int prezzo;
    } Libro;

    int p;
    int fd[2]; // file descriptor della pipe
    if (pipe(fd) < 0)
    {
        printf("Errore creazione pipe");
        exit(-1);
    }

    p = fork();

    if (p < 0)
    {
        printf("Errore creazione fork");
        close(fd[0]);
        close(fd[1]);
        exit(-1);
    }

    if (p == 0)
    {
        // figlio
        Libro buffer;
        close(fd[1]); // chiuso scrittura
        for (int i = 0; i < 2; i++)
        {
            read(fd[0], &buffer, sizeof(buffer)); // leggo la struct passata dal padre
            printf("Autore del libro %d : %s\n", i, buffer.autore);
            printf("Titolo del libro %d : %s\n", i, buffer.titolo);
            printf("Prezzo del libro %d : %d\n", i, buffer.prezzo);
        }
        close(fd[0]);
    }
    else
    {
        // padre
        close(fd[0]); // chiuso lettura

        Libro libro; // variabile struct

        for (int i = 0; i < 2; i++)
        {
            printf("Inserire titolo del libro \n");
            scanf("%s", libro.titolo);
            printf("Inserire autore del libro \n");
            scanf("%s", libro.autore);
            printf("Inserire prezzo del libro \n");
            scanf("%d", &libro.prezzo);
            write(fd[1], &libro, sizeof(libro));
        }

        close(fd[1]); // chiuso pipe
    }
    return 0;
}