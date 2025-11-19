/*Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il
server riceve in input un vettore di numeri e dopo aver effettuato gli eventuali
ed opportuni controlli (se necessari), rispedisce al Client il conteggio dei
numeri pari e dei numeri dispari contenuti nel vettore.*/
// CLIENT
#include <ctype.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define DIM 50
#define SERVERPORT 1313

int main(int argc, char **argv) {

  struct sockaddr_in servizio;
  int socketfd, dimensione;
  char buffer[DIM];

  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);
  servizio.sin_port = htons(SERVERPORT);

  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    printf("Quanti numeri vuoi inserire?");
    scanf("%d",&dimensione);

    int vettore[dimensione];
    for(int i=0; i<dimensione;i++){
        printf("\nNumero %d: ",i+1);
        scanf("%d",&vettore[i]);
    }
    write(socketfd,&dimensione,sizeof(int));
    write(socketfd,vettore,dimensione* sizeof(int));

    read(socketfd, buffer,DIM);
    printf("Risultato: %s",buffer);

  close(socketfd);
  return 0;
}