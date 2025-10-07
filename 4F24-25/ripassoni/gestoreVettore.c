/*Esercizio Gestione del Vettore
Scrivere un programma in C che effettui, attraverso un menù, le seguenti
operazione sugli array: 1) Visualizzi a video gli elementi dell’array inseriti o
generati casualmente; 2) Visualizzi a video l’array invertito, cioè, sostituendo
il primo elemento con l’ultimo, il secondo con il penultimo e così via; 3)
Visualizzi a video la somma e media degli elementi del vettore; 4) Visualizzi a
video tutti i numeri pari; 5) Visualizzi a video tutti i numeri dispari; 6)
Ricerchi un numero (letto in input) nell’array; 7) Elimini un elemento (letto in
input) dell’array (se esistente); 8) Alterni (o scambi) a due a due le posizioni
del vettore: esempio vettore: 1,2,3,4 vettore alternato: 2,1,4,3 (attenzione se
lungo dispari); 9) Ordini il vettore (ordinamento a scelta). */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VETT_DIM 300

void visualizza(int vett[], int n) {
  if (n == 0) {
    printf("Vettore vuoto!!\n");
    return;
  }
  printf("Vettore: ");
  for (int i = 0; i < n; i++) {
    printf("%d", vett[i]);
  }
  printf("\n");
}

void inverti(int vett[], int n) {
  for (int i = 0; i < n / 2; i++) {
    int temp = vett[i];
    vett[i] = vett[n - 1 - i];
    vett[n - 1 - i] = temp;
  }
  printf("Il vettore è stato robaltaint *vettto!!\n");
}

void somma_media(int vett[], int n) {
  if (n == 0) {
    printf("Vettore vuoto!!\n");
    return;
  }
  int somma = 0;
  for (int i = 0; i < n; i++) {
    somma += vett[i];
  }
  float media = (float)somma / n;
  printf("La somma è: %d, la media è: %.2f\n", somma, media);
}

void visualizza_Npari(int vett[], int n) {
  printf("Numeri pari nel vettore: ");
  for (int i = 0; i < n; i++) {
    if (vett[i] % 2 == 0) {
      printf("%d", vett[i]);
    }
  }
  printf("\n");
}

void visualizza_Ndispari(int vett[], int n) {
  printf("Numeri dispari nel vettore: ");
  for (int i = 0; i < n; i++) {
    if (vett[i] % 2 != 0) {
      printf("%d", vett[i]);
    }
  }
  printf("\n");
}

void cerca_num(int vett[], int n) {
  int num;
  printf("Inserisci numero da ricercare nel vettore: ");
  scanf("%d", &num);
  for (int i = 0; i < n; i++) {
    if (vett[i] == num) {
      printf("Il numero è stato trovato in posizione %d\n", i);
      return;
    }
  }
  printf("Numero non trovato!!\n");
}

int elimina_num(int vett[], int *n) {
  int num, trovato = 0;
  printf("Inserisci il numero da eliminare: ");
  scanf("%d", &num);
  for (int i = 0; i < *n; i++) {
    if (vett[i] == num) {
      trovato = 1;
      for (int j = 0; j < *n - 1; j++) {
        vett[j] = vett[j + 1];
      }
      (*n)--;
      printf("Numero eliminato!\n");
      break;
    }
  }
  if (!trovato) {
    printf("Numero non trovato!!\n");
  }
  return trovato;
}

void alterna_coppie(int vett[], int n) {
  for (int i = 0; i < n - 1; i += 2) {
    int temp = vett[i];
    vett[i] = vett[i + 1];
    vett[i + 1] = temp;
  }
  printf("Il vettore è stato alternato!!\n");
}

void ordinamento(int vett[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (vett[j] > vett[j + 1]) {
        int temp = vett[j + 1];
        vett[j] = vett[j + 1];
        vett[j + 1] = temp;
      }
    }
  }
  printf("Vettore ordinato!!\n");
}

void generazioneVett(int vett[], int *n) {
  printf("Quanti numeri vuoi generare (max %d) ", VETT_DIM);
  scanf("%d", n);
  if (*n > VETT_DIM)
    *n = VETT_DIM;
  srand(time(NULL));
  for (int i = 0; i < *n; i++) {
    vett[i] = rand() % 100;
  }
  printf("Generazione completata!\n");
}

int main(int argc, char *argv[]) {

  int vettore[VETT_DIM];
  int n = 0;
  int scelta;
  do {
    printf("---MENÙ BELLISSIMO---\n");
    printf("1- Genera un vettore\n");
    printf("2- Visualizzazione\n");
    printf("3- Inversione\n");
    printf("4- Somma e media\n");
    printf("5- Visualizzazione numeri pari\n");
    printf("6- Visualizzazione numeri dispari\n");
    printf("7- Cerca numero\n");
    printf("8- Elimina numero\n");
    printf("9- Alterna coppie\n");
    printf("10- Ordinamento\n");
    printf("0- Esci\n");
    printf("Scegli sta cazzo di opzione:   ");
    scanf("%d", &scelta);

    switch (scelta) {
    case 1:
      generazioneVett(vettore, &n);
      break;
    case 2:
      visualizza(vettore, n);
      break;
    case 3:
      inverti(vettore, n);
      break;
    case 4:
      somma_media(vettore, n);
      break;
    case 5:
      visualizza_Npari(vettore, n);
      break;
    case 6:
      visualizza_Ndispari(vettore, n);
      break;
    case 7:
      cerca_num(vettore, n);
      break;
    case 8:
      elimina_num(vettore, &n);
      break;
    case 9:
      alterna_coppie(vettore, n);
      break;
    case 10:
      ordinamento(vettore, n);
      break;
    case 0:
      printf("Programma finito...\n");
      break;
    default:
      printf("scelta non valida\n");
      break;
    }

  } while (scelta != 0);

  return 0;
}