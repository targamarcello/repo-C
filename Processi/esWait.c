#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void calcola_prodotto(int *vettore) {
    int prodotto = 1;
    for (int i = 0; i < 3; i++) {
        prodotto *= vettore[i];
    }
    printf("P4: Il prodotto delle componenti del vettore V[] = %d\n", prodotto);
}

void calcola_media(int *vettore) {
    int somma = 0;
    for (int i = 0; i < 3; i++) {
        somma += vettore[i];
    }
    float media = somma / 3;
    printf("P5: La media delle componenti del vettore V[] = %.2f\n", media);
}

void calcola_somma(int *vettore) {
    int somma = 0;
    for (int i = 0; i < 3; i++) {
        somma += vettore[i];
    }
    printf("P6: La somma delle componenti del vettore V[] = %d\n", somma);
    exit(somma);
}

int main() {
    pid_t pidP2, pidP3, pidP4, pidP5, pidP6;
    int vettore[3];
    srand(time(NULL));

    // Generazione del vettore V[3]
    printf("P1: mio PID=%d, sto generando il vettore V[]\n", getpid());
    for (int i = 0; i < 3; i++) {
        vettore[i] = rand() % 6;
    }

    pidP2 = fork();

    if (pidP2 == 0) { // Processo P2
        printf("P2: mio PID=%d, mio padre P1 ha PID=%d\n", getpid(), getppid());

        pidP4 = fork();
        if (pidP4 == 0) { // Processo P4
            printf("P4: mio PID=%d, mio padre P2 ha PID=%d\n", getpid(), getppid());
            calcola_prodotto(vettore);
            exit(0);
        }

        pidP5 = fork();
        if (pidP5 == 0) { // Processo P5
            printf("P5: mio PID=%d, mio padre P2 ha PID=%d\n", getpid(), getppid());
            calcola_media(vettore);
            exit(0);
        }

        // Attesa di P4 e P5
        wait(NULL);
        wait(NULL);
        exit(0);
    }

    pidP3 = fork();

    if (pidP3 == 0) { // Processo P3
        printf("P3: mio PID=%d, mio padre P1 ha PID=%d\n", getpid(), getppid());

        printf("P3: Il vettore V[] = [%d, %d, %d]\n", vettore[0], vettore[1], vettore[2]);

        pidP6 = fork();
        if (pidP6 == 0) { // Processo P6
            printf("P6: mio PID=%d, mio padre P3 ha PID=%d\n", getpid(), getppid());
            calcola_somma(vettore);
        }

        int status;
        waitpid(pidP6, &status, 0);
        if (WIFEXITED(status)) {
            int risultato = WEXITSTATUS(status);
            printf("P3: La somma calcolata da P6 = %d\n", risultato);
        }
        exit(0);
    }

    // Attesa di P2 e P3
    wait(NULL);
    wait(NULL);

    printf("P1: Fine dell'esecuzione\n");
    return 0;
}