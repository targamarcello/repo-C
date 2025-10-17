#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char modello[50];
    char marca[50];
    int cilindrata;
    float prezzo;
    int anno;
    char targa[20];
}Auto;

void inserisciAuto(Auto a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nAuto %d:\n", i + 1);
        printf("Modello: ");
        scanf("%s", a[i].modello);
        printf("Marca: ");
        scanf("%s", a[i].marca);
        printf("Cilindrata: ");
        scanf("%d", &a[i].cilindrata);
        printf("Prezzo: ");
        scanf("%f", &a[i].prezzo);
        printf("Anno immatricolazione: ");
        scanf("%d", &a[i].anno);
        printf("Targa: ");
        scanf("%s", a[i].targa);
    }
}

void mostraAuto(Auto a) {
    printf("\nModello: %s", a.modello);
    printf("\nMarca: %s", a.marca);
    printf("\nCilindrata: %d", a.cilindrata);
    printf("\nPrezzo: %.2f", a.prezzo);
    printf("\nAnno: %d", a.anno);
    printf("\nTarga: %s\n", a.targa);
}

void prezzoMaxMin(Auto a[], int n) {
    int max = 0, min = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].prezzo > a[max].prezzo) max = i;
        if (a[i].prezzo < a[min].prezzo) min = i;
    }
    printf("\nAuto con prezzo massimo:\n");
    mostraAuto(a[max]);
    printf("\nAuto con prezzo minimo:\n");
    mostraAuto(a[min]);
}

void ordinaPerAnno(Auto a[], int n) {
    Auto temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].anno > a[j].anno) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void visualizzaDaPrezzo(Auto a[], int n, float prezzo) {
    int trovata = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].prezzo >= prezzo) {
            mostraAuto(a[i]);
            trovata = 1;
        }
    }
    if (!trovata)
        printf("Nessuna auto trovata con prezzo >= %.2f\n", prezzo);
}

void cercaPerTarga(Auto a[], int n, char targa[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].targa, targa) == 0) {
            mostraAuto(a[i]);
            return;
        }
    }
    printf("Nessuna auto trovata con la targa %s\n", targa);
}

float mediaPrezzi(Auto a[], int n) {
    float somma = 0;
    for (int i = 0; i < n; i++)
        somma += a[i].prezzo;
    return somma / n;
}

void visualizzaPerAnno(Auto a[], int n, int anno) {
    int trovata = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].anno == anno) {
            mostraAuto(a[i]);
            trovata = 1;
        }
    }
    if (!trovata)
        printf("Nessuna auto trovata dell'anno %d\n", anno);
}
int main(int argc, char *argv[]) {
    Auto a[MAX];
    int n, scelta, anno;
    float prezzo;
    char targa[20];

    printf("Quante auto vuoi inserire? ");
    scanf("%d", &n);

    inserisciAuto(a, n);

    do {
        printf("\n--- MENU ---\n");
        printf("1) Prezzo massimo e minimo\n");
        printf("2) Ordina per anno di immatricolazione\n");
        printf("3) Visualizza auto da un prezzo minimo\n");
        printf("4) Cerca auto per targa\n");
        printf("5) Media dei prezzi\n");
        printf("6) Visualizza auto per anno\n");
        printf("0) Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                prezzoMaxMin(a, n);
                break;
            case 2:
                ordinaPerAnno(a, n);
                printf("\nAuto ordinate per anno:\n");
                for (int i = 0; i < n; i++)
                    mostraAuto(a[i]);
                break;
            case 3:
                printf("Inserisci un prezzo minimo: ");
                scanf("%f", &prezzo);
                visualizzaDaPrezzo(a, n, prezzo);
                break;
            case 4:
                printf("Inserisci la targa: ");
                scanf("%s", targa);
                cercaPerTarga(a, n, targa);
                break;
            case 5:
                printf("Media prezzi: %.2f\n", mediaPrezzi(a, n));
                break;
            case 6:
                printf("Inserisci anno: ");
                scanf("%d", &anno);
                visualizzaPerAnno(a, n, anno);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida.\n");
        }
    } while (scelta != 0);

    return 0;
}