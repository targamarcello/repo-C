#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("\nDati dello studente ricevuti da P1:\n");
    printf("Nome: %s\n", argv[1]);
    printf("Cognome: %s\n", argv[2]);
    printf("Età: %d\n", atoi(argv[3]));

    return 0;
}
