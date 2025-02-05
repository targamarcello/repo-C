#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  pid_t f1, f2;
  int p, pp;
  f1 = fork();
  if (f1 > 0) {
    printf("P = %d, mio figlio F1 = %d\n", getpid(), p);
    f2 = fork();
    if (f2 > 0) {
      printf("P = %d, mio figlio F2 = %d\n", getpid(), f2);
    } else if (f2 == 0) {
      wait(&f1);
      printf("F2 = %d, mio papà ha PID = %d\n", getpid(), getppid());
      printf("Ora faccio un pisolino di 4 secondi\n");
      sleep(4);
      exit(4);
    }
  } else if (f1 == 0) {
    printf("F1 = %d, mio papà ha PID = %d\n", getpid(), getppid());
    printf("Ora faccio un pisolino di 2 secondi\n");
    sleep(2);
    exit(2);
  } else {
    printf("Errore!!");
    exit(1);
  }
  p = waitpid(f1, &f1, 0);
  printf("Mio figlio %d ha dormito per %d secondi\n", p, WEXITSTATUS(f1));
  pp = waitpid(f2, &f2, 0);
  printf("Mio figlio %d ha dormito per %d secondi\n", pp, WEXITSTATUS(f2));
  return 0;
}

/*Scrivi il codice sorgente di un prg in cui
   il processo padre P genera due figli: F1 e  F2.

   A F1 assegna un tempo t di sleep(t) (ritardo) 2 secondi;
   F1 deve restituire al padre P il numero 2.
   A F2 assegna un tempo t di sleep(t) (ritardo) 4 secondi;
   F2 deve restituire al padre P il numero 4.

   Padre P deve attendere la terminazione del figlio che dorme di piÃ¹, ossia
   F2, e deve scrivere quanti secondi ha dormito tale figlio.

   La prima cosa che ciascun processo deve fare, appena genera un processo
   figlio, Ã¨ dichiararsi nel modo seguente: "P: mio PID=..., mio figlio F1 ha
   PID=... La prima cosa che ciascun processo figlio deve fare appena Ã¨ stato
   generato, Ã¨ dichiararsi nel modo seguente: "F1: mio PID=..., mio padre P ha
   PID=..."

   Ogni volta che un processo visualizza qualcosa sullo schermo deve dichiararsi
   nel modo seguente: "P: quello che P deve visualizzare"
   "..."*/