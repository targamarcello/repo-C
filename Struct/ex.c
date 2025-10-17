#include <stdio.h>
#include <string.h>

// Definizione della struttura per rappresentare una persona
typedef struct
{
    char nome[50];
    char cognome[50];
    int eta;
    float altezza;
} Persona;

/*void stampaDettagli(Persona p){
    printf("Dettagli della struttura:\n");
    printf("Nome: %s\n",p.nome);
    printf("Cognome: %s\n",p.cognome);
    printf("Età: %d\n",p.eta);
    printf("Altezza: %.2f\n",p.altezza);
}*/
void aggiornaEta(Persona *p, int eta2)
{
    (*p).eta = eta2;
}

int main()
{
    Persona p1 = {"Luigi", "Verdi", 41, 1.31};
    // stampaDettagli(p1);
    printf("Età prima: %d\n", p1.eta);
    aggiornaEta(&p1, 41);
    printf("Età dopo: %d\n", p1.eta);

    return 0;
}
