#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t f1, f2;
    int somma = 0;
    f1 = fork();
    if (f1 > 0)
    { // Padre
        printf("Padre = %d, mio figlio ha PID = %d\n", getpid(), f1);
        f2 = fork();
        if (f2 >0)
        {
            printf("Padre = %d, mio figlio ha PID = %d\n",getpid(),f2);
        }else if(f2 ==0){
            printf("F2 = %d, mio padre ha PID = %d\n",getpid(),getppid());
            somma = 3+4;
            exit(somma);
        }
    }
    else if (f1 == 0)
    {
        printf("F1 = %d, mio padre ha PID = %d\n", getpid(), getppid());
        somma = 1 + 2;
        exit(somma);
    }
    else
    {
        printf("Errore brutto!!!!!\n");
    }
    wait(&f1);
    printf("F1 ha ritornato %d\n", WEXITSTATUS(f1));
    wait(&f2);
    printf("F2 ha ritornato %d\n", WEXITSTATUS(f2));
    return 0;
}

/*Scrivi il codice sorgente di un prg in cui
   il processo padre P genera due processi figli: F1 e F2.
   F1 somma 1+2;
   F2 somma 3+4.
   Entrambi restituiscono al processo padre P il risultato ottenuto dall'operazione compiuta.
   Padre P somma tra loro i risultati che i due figli gli hanno restituito e
   visalizza il valore di tale somma.

   La prima cosa che ciascun processo deve fare, appena genera un processo figlio,
   Ã¨ dichiararsi nel modo seguente:
   "P: mio PID=..., mio figlio F1 ha PID=...
   La prima cosa che ciascun processo figlio deve fare appena Ã¨ stato generato,
   Ã¨ dichiararsi nel modo seguente:
   "F1: mio PID=..., mio padre P ha PID=..."

   Ogni volta che un processo visualizza qualcosa sullo schermo deve dichiararsi nel modo seguente:
   "P: quello che P deve visualizzare" */