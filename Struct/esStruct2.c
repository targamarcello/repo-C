/*Scrivere un programma in C che dopo aver dichiarato una struttura denominata Persona con i
seguenti campi: Nome, Cognome, età, codice fiscale, reddito annuo, anno_nascita,residenza(città) ;
determini:
1) La persona con reddito annuo più alto e quella con reddito annuo più basso.Visualizzare
per entrambe: nome, cognome, città e reddito.
2) Ordinare la lista delle persone in base all’anno di nascita** (dal più anziano al più
giovane), e visualizzarla.
3) Consentire all’utente di cercare una persona inserendo il codice fiscale..
4) Visualizzare tutte le persone con reddito superiore o uguale a un valore scelto dall’utente.
5) Calcolare la media dei redditi delle persone registrate nel sistema.
6) Visualizzare tutte le persone nate in un anno specifico, scelto dall’utente;
7) Visualizzare l'elenco delle persone raggruppate per città di residenza, indicando per
ciascuna città: Quante persone vi risiedono, L’età media dei residenti*/

#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct
{
    char nome[20];
    char cognome[20];
    int eta;
    char cf[16];
    float redditoAnnuo;
    int annoNascita;
    char citta[20];
} Persona;

/**
 * @brief Richiede all'utente di inserire i dati di n persone.
 * 
 * @param p Array di strutture Persona in cui memorizzare i dati.
 * @param n Puntatore a intero dove viene salvato il numero di persone inserite.
 * 
 * @return void
 */
void inserimento(Persona p[], int *n)
{
    printf("Quante persone vuoi inserire? ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
    {
        printf("\n Persona %d:\n", i + 1);
        printf("\n Nome: ");
        scanf("%s", p[i].nome);
        printf("\n Cognome: ");
        scanf("%s", p[i].cognome);
        printf("\n Età: ");
        scanf("%d", &p[i].eta);
        printf("\n Codice Fiscale: ");
        scanf("%s", p[i].cf);
        printf("\n Reddito annuo: ");
        scanf("%f", &p[i].redditoAnnuo);
        printf("\n Anno nascita: ");
        scanf("%d", &p[i].annoNascita);
        printf("\n Città residenza: ");
        scanf("%s", p[i].citta);
    }
}

/**
 * @brief Trova e stampa la persona con reddito massimo e quella con reddito minimo.
 * 
 * @param p Array di persone.
 * @param n Numero totale di persone nel sistema.
 * 
 * @return void
 */
void redditoMax_Min(Persona p[], int n)
{
    int max = 0, min = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].redditoAnnuo > p[max].redditoAnnuo)
            max = i;
        if (p[i].redditoAnnuo < p[min].redditoAnnuo)
            min = i;
    }
    printf("Reddito Massimo: %s, %s, %s, %.2f", p[max].nome, p[max].cognome, p[max].citta, p[max].redditoAnnuo);
    printf("Reddito Minimo: %s, %s, %s, %.2f", p[min].nome, p[min].cognome, p[min].citta, p[min].redditoAnnuo);
}

/**
 * @brief Ordina l'array di persone per anno di nascita (dal più anziano al più giovane).
 * 
 * @param p Array di persone.
 * @param n Numero di persone nell'array.
 * 
 * @return void
 */
void ordinamento(Persona p[], int n)
{
    Persona temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = j + 1; j < n; j++)
        {
            if (p[i].annoNascita > p[j].annoNascita)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("Array ordinato\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s,%s,%d,%s\n", p[i].nome, p[i].cognome, p[i].annoNascita, p[i].citta);
    }
}

/**
 * @brief Cerca una persona in base al codice fiscale e la stampa se trovata.
 * 
 * @param p Array di persone.
 * @param n Numero di persone.
 * @param codice Codice fiscale da cercare.
 * 
 * @return void
 */
void ricerca(Persona p[], int n, char codice[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(p[i].cf, codice) == 0)
        {
            printf("%s,%s,%d anni, %s, reddito: %.2f\n", p[i].nome, p[i].cognome, p[i].eta, p[i].citta, p[i].redditoAnnuo);
            break;
        }
    }
}

/**
 * @brief Visualizza tutte le persone con reddito annuo superiore o uguale a un valore scelto dall’utente.
 * 
 * @param p Array di persone.
 * @param n Numero totale di persone.
 * 
 * @return void
 */
void visualizzaReddito(Persona p[], int n)
{
    float val;
    printf("Inserire valore minimo di reddito: ");
    scanf("%f", &val);
    for (int i = 0; i < n; i++)
    {
        if (p[i].redditoAnnuo >= val)
        {
            printf("%s,%s,%s,%.2f\n", p[i].nome, p[i].cognome, p[i].citta, p[i].redditoAnnuo);
        }
    }
}

/**
 * @brief Calcola e stampa la media dei redditi annui delle persone registrate.
 * 
 * @param p Array di persone.
 * @param n Numero di persone.
 * 
 * @return void
 */
void mediaReddito(Persona p[], int n)
{
    float somma = 0;
    for (int i = 0; i < n; i++)
    {
        somma += p[i].redditoAnnuo;
    }
    printf("La media dei redditi è %.2f\n", somma / n);
}

/**
 * @brief Visualizza tutte le persone nate in un anno specifico scelto dall’utente.
 * 
 * @param p Array di persone.
 * @param n Numero totale di persone.
 * 
 * @return void
 */
void visualizzaNascita(Persona p[], int n)
{
    int anno;
    int trovato = 0;
    printf("Inserisci l'anno su cui fare la ricerca: ");
    scanf("%d\n", &anno);
    for (int i = 0; i < n; i++)
    {
        if (p[i].annoNascita == anno)
        {
            printf("%s,%s,%d,%s,%s", p[i].nome, p[i].cognome, p[i].eta, p[i].cf, p[i].citta);
            trovato = 1;
        }
    }
    if (!trovato)
        printf("Nessuna persona trovata con quell'anno di nascita!!\n");
}

//void raggruppamentoCitta(); // non ho idee

/**
 * @brief Funzione principale del programma. Gestisce il menu e le operazioni.
 * 
 * @return int Codice di uscita del programma (0).
 */
int main()
{
    Persona persone[MAX];
    int scelta, n = 0;
    char cfCercato[16];
    // qua avviene l'inserimento delle persone
    inserimento(persone, &n);

    do
    {
        printf("\n====MENU'====");
        printf("1-Reddito Max e Min\n");
        printf("2-Orinamento array persone\n");
        printf("3-Ricerca con cf\n");
        printf("4-Visualizzazione dal reddito\n");
        printf("5-Media redditi\n");
        printf("6-Visualizza per data nascita\n");
        printf("7-Raggruppaento città\n");
        printf("0-Esci");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:
        redditoMax_Min(persone,n);
            break;
        case 2:
        ordinamento(persone,n);
            break;
        case 3:
        printf("Inserisci codice fiscale da ricercare: ");
        scanf("%s",cfCercato);
        ricerca(persone,n,cfCercato);
            break;
        case 4:
        visualizzaReddito(persone,n);
            break;
        case 5:
        mediaReddito(persone,n);
            break;
        case 6:
        visualizzaNascita(persone,n);
            break;
        case 7:
        //raggruppamentoCitta(persone,n);
            break;
        case 0:
            printf("Uscita dal programma...\n");
            break;
        default:
            printf("Scelta sbagliata!!!\n");
        }

    } while (scelta != 0);

    return 0;
}
