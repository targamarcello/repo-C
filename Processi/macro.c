#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{

    int p, pid, status;
    printf("Genitore: %d\n", getpid());
    p = fork();
    if (p > 0) // P
    {
        printf("P: %d, mio figlio ha PID: %d\n", getpid(), p);
        pid = wait(&status);
        if (WIFEXITED(status))
        {
            printf("Genitore, mio figlio non è terminato correttamente: %d\n", WTERMSIG(status));
        }
    }

    else if (p == 0)
    { // Figlio
        printf("Figlio: %d, mio padre ha PID: %d\n", getpid(), getppid());
        printf("Figlio, sto dando a mio padre il numero 25\n");
        exit(25);
    }
    else
    {
        printf("SI È VERIFICATO UN ERRORE, MALEDETTO!!\n");
        exit(1);
    }

    return 0;
}